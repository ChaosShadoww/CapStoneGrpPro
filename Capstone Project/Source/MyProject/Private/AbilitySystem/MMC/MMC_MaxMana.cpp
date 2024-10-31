// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MMC/MMC_MaxMana.h"

#include "AbilitySystem/HeroAttributeSet.h"
#include <Interaction/CombatInterface.h>

UMMC_MaxMana::UMMC_MaxMana()
{
	//Get Intelligence, apply attribute from source to target (in this case from hero to itself, and add this attribute for calc
	IntelligenceDef.AttributeToCapture = UHeroAttributeSet::GetIntelligenceAttribute();
	IntelligenceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	IntelligenceDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(IntelligenceDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	//Gather tags from source and target
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	// Tags needed in order to capture the attribute we are interested in
	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Intelligence = 0.f;
	GetCapturedAttributeMagnitude(IntelligenceDef, Spec, EvaluationParameters, Intelligence);
	//Clamp, if con < 0 set to 0
	Intelligence = FMath::Max<float>(Intelligence, 0.f);
	//We now have constitution value now we need level

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	//default values
	return 20.f + 6.f * Intelligence + 10 * PlayerLevel;
}
