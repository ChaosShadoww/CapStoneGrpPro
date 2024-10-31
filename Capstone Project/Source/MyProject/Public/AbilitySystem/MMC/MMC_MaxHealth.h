// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_MaxHealth.generated.h"

/**
 * Calculate Custom Calculation
 */
UCLASS()
class MYPROJECT_API UMMC_MaxHealth : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
public:
	UMMC_MaxHealth();

	//returns result modifier produces, can capture attributes and have access to EffectSpec
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:
	//struct that defines what attribute we capture
	FGameplayEffectAttributeCaptureDefinition  ConstitutionDef;
};
