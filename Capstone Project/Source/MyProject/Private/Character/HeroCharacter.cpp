// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/HeroCharacter.h"
#include "Player/HeroPlayerState.h"
#include "AbilitySystem/HeroAbilitySystemComponent.h"
#include "Player/HeroPlayerController.h"
#include "UI/HUD/HeroHUD.h"
#include "PaperFlipbookComponent.h"



void AHeroCharacter::Turn(float TurnVector)
{
	if (TurnVector > 0)
	{
		HeroSprite->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	}
	if (TurnVector < 0)
	{
		HeroSprite->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	}
}

void AHeroCharacter::InitAbilityActorInfo()
{
	AHeroPlayerState* HeroPlayerState = GetPlayerState<AHeroPlayerState>();
	check(HeroPlayerState);
	HeroPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(HeroPlayerState, this);
	AbilitySystemComponent = HeroPlayerState->GetAbilitySystemComponent();
	AttributeSet = HeroPlayerState->GetAttributeSet();

	if (AHeroPlayerController* HeroPlayerController = Cast<AHeroPlayerController>(GetController()))
	{
		if (AHeroHUD* HeroHUD = Cast<AHeroHUD>(HeroPlayerController->GetHUD()))
		{
			HeroHUD->InitOverlay(HeroPlayerController, HeroPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}

}

void AHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the Server
	InitAbilityActorInfo();
}

void AHeroCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilityActorInfo();
}

