// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/HeroCharacter.h"
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
