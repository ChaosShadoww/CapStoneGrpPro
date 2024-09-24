// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/HeroPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AHeroPlayerController::AHeroPlayerController()
{
	bReplicates = true;											// changes can be made between server and clients 
}

void AHeroPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AHeroPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(HeroContext);										//check to see if IMC is set

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()); //to add IMappingContext

	check(Subsystem);										//check subsystem, will crash without subsystem
	Subsystem->AddMappingContext(HeroContext, 0);			// to retrieve data for controller, use priority

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;											//input mode struct so we can use input to affect widget ui
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);	// mouse not locked to viewport
	InputModeData.SetHideCursorDuringCapture(false);							// don't hide cursor
	SetInputMode(InputModeData);												//apply input mode data
}

void AHeroPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AHeroPlayerController::Move);
}

void AHeroPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AHeroPlayerController::CursorTrace()
{
	//Get hit result under cursor
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;


	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	/*
	* LINE TRACE FROM CURSOR. SCENARIOS:
	*	A. LastActor is null ThisActor is null
	*		- Do nothing
	*	B. LastActor is null, ThisActor is valid
	*		- Highlight ThisActor
	*	C LastActor is valid, ThisActor is null
	*		- Unhighlight LastActor
	*	D. Both are valid, LastActor != ThisActor
	*		- Unhighlight LastActor
	*		- Highlight ThisActor
	*	E. Both are valid, LastActor == ThisActor
	*		- Do nothing
	*
	*/

	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			// Case B
			ThisActor->HighlightActor();
		}
		else
		{
			//Case A - both null do nothing
		}
	}
	else // LastActor is Valid
	{
		if (ThisActor == nullptr)
		{
			// Case C
			LastActor->UnHighlightActor();
		}
		else // both are valid
		{
			if (LastActor != ThisActor)
			{
				// Case D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else 
			{
				// Case E - both valid and same actor, do nothing
			}
		}
	}
}
