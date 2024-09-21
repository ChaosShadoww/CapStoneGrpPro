// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "PaperSpriteComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PaperCharacterBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class MYPROJECT_API APaperCharacterBase : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	APaperCharacterBase();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category = "Combat")				// PaperSprite Component for weapon
	TObjectPtr<UPaperSpriteComponent> Sward;

	UPROPERTY(EditAnywhere, Category = "Character")
	TObjectPtr<UPaperFlipbookComponent> HeroSprite = GetSprite();

	UPROPERTY(EditAnywhere, Category = "SpringArm")				// SpringArm Component
	TObjectPtr<USpringArmComponent> HeroSpringArm;

	UPROPERTY(EditAnywhere, Category = "Camera")				// Camera Component
	TObjectPtr<UCameraComponent> HeroCamera;
};
