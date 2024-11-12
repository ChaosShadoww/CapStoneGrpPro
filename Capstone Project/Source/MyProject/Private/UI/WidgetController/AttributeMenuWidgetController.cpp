// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include <AbilitySystem/HeroAttributeSet.h>
#include "AbilitySystem/Data/AttributeInfo.h"
#include "HeroGameplayTags.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	UHeroAttributeSet* AS = CastChecked<UHeroAttributeSet>(AttributeSet);

	check(AttributeInfo);
	for (auto& Pair : AS->TagsToAttribute)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
			[this, Pair/*, AS*/](const FOnAttributeChangeData& Data)
			{
				BroadcastAttributeInfo(Pair.Key, Pair.Value());
				/* This code is replaced by the function above
				FHeroAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
				Info.AttributeValue = Pair.Value().GetNumericValue(AS);
				AttributeInfoDelegate.Broadcast(Info);*/
			}
		);
	}
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UHeroAttributeSet* AS = CastChecked<UHeroAttributeSet>(AttributeSet);

	check(AttributeInfo);

	//FHeroAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(FHeroGameplayTags::Get().Attributes_Primary_Strength);
	//Info.AttributeValue = AS->GetStrength();
	//AttributeInfoDelegate.Broadcast(Info);

	//Loop Through map from HeroAttributeSet, TStaticFuncPtr
	for (auto& Pair : AS->TagsToAttribute)
	{
		BroadcastAttributeInfo(Pair.Key, Pair.Value());
		/*
		FHeroAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
		/*FGameplayAttribute Attr = Pair.Value.Execute();
		Info.AttributeValue = Attr.GetNumericValue(AS);
		Info.AttributeValue = Pair.Value().GetNumericValue(AS);
		AttributeInfoDelegate.Broadcast(Info);*/
	}

}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const
{
	FHeroAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}

