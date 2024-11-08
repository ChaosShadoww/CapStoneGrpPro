// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * HeroGameplayTags
 * 
 * Singleton containing native Gameplay Tags
 */
struct FHeroGameplayTags
{
public:
	//static getter function to access instance of this struct
	static const FHeroGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Dexterity;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Constitution;
	FGameplayTag Attributes_Primary_Wisdom;

	FGameplayTag Attributes_Secondary_ArmorClass;
	FGameplayTag Attributes_Secondary_ArmorPenetration;
	FGameplayTag Attributes_Secondary_BlockChance;
	FGameplayTag Attributes_Secondary_CriticalHitChance;
	FGameplayTag Attributes_Secondary_CriticalHitDamage;
	FGameplayTag Attributes_Secondary_CriticalHitResistance;
	FGameplayTag Attributes_Secondary_HealthRegen;
	FGameplayTag Attributes_Secondary_ManaRegen;
	FGameplayTag Attributes_Secondary_MaxHealth;
	FGameplayTag Attributes_Secondary_MaxMana;
	FGameplayTag Attributes_Secondary_Perception;
	FGameplayTag Attributes_Secondary_Stealth;
	FGameplayTag Attributes_Secondary_Investigation;

protected:

private:
	//Instance variable
	static FHeroGameplayTags GameplayTags;
};