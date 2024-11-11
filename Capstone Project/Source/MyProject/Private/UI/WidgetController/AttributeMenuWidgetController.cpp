// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include <AbilitySystem/HeroAttributeSet.h>
#include "AbilitySystem/Data/AttributeInfo.h"
#include "HeroGameplayTags.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
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
		FHeroAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
		/*FGameplayAttribute Attr = Pair.Value.Execute();
		Info.AttributeValue = Attr.GetNumericValue(AS);*/
		Info.AttributeValue = Pair.Value().GetNumericValue(AS);
		AttributeInfoDelegate.Broadcast(Info);
	}

}
