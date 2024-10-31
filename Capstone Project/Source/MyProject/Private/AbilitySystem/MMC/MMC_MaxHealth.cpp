// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MMC/MMC_MaxHealth.h"

#include "AbilitySystem/HeroAttributeSet.h"
#include <Interaction/CombatInterface.h>

UMMC_MaxHealth::UMMC_MaxHealth()
{

	//Get Constitution, apply attribute from source to target (in this case from hero to itself, and add this attribute for calc
	ConstitutionDef.AttributeToCapture = UHeroAttributeSet::GetConstitutionAttribute();
	ConstitutionDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	ConstitutionDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(ConstitutionDef);
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	//Gather tags from source and target
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	// Tags needed in order to capture the attribute we are interested in
	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Constitution = 0.f;
	GetCapturedAttributeMagnitude(ConstitutionDef, Spec, EvaluationParameters, Constitution);
	//Clamp, if con < 0 set to 0
	Constitution = FMath::Max<float>(Constitution, 0.f);
	//We now have constitution value now we need level

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	//default values
	return 50.f + 4.f * Constitution + 10 * PlayerLevel;
}
