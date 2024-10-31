// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "PaperZDCharacter.h"
#include "PaperSpriteComponent.h"
#include "Camera/CameraComponent.h"
#include "Interaction/CombatInterface.h"
#include "GameFramework/SpringArmComponent.h"
#include "PaperCharacterBase.generated.h"


class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;
/**
 * 
 */
UCLASS(Abstract)
class MYPROJECT_API APaperCharacterBase : public APaperZDCharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	APaperCharacterBase();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

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

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	virtual void InitAbilityActorInfo();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect>  DefaultVitalAttributes;

	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const;
	void InitializeDefaultAttributes() const;
	/*
	void InitializePrimaryAttributes() const;
	void InitializeSecondaryAttributes() const;
	*/
};
