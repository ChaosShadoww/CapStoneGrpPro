// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroGameplayTags.h"
#include "GameplayTagsManager.h"

FHeroGameplayTags FHeroGameplayTags::GameplayTags;

void FHeroGameplayTags::InitializeNativeGameplayTags()
{
	UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces damage taken, improves Block Chance."));
}
