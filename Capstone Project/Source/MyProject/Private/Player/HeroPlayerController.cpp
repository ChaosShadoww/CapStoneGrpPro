// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/HeroPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AHeroPlayerController::AHeroPlayerController()
{
	bReplicates = true;											// changes can be made between server and clients 
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
