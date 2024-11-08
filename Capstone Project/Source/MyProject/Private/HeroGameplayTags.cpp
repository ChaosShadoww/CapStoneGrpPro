// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroGameplayTags.h"
#include "GameplayTagsManager.h"

FHeroGameplayTags FHeroGameplayTags::GameplayTags;

void FHeroGameplayTags::InitializeNativeGameplayTags()
{
	/**
	 * 
	 *	Primary Attributes
	 */
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Strength"),
		FString("Increases physical damage."));
	GameplayTags.Attributes_Primary_Dexterity = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Dexterity"),
		FString("Increases armor and block chance."));
	GameplayTags.Attributes_Primary_Constitution = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Constitution"),
		FString("Increases health."));
	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Intelligence"),
		FString("Increases magical damage."));
	GameplayTags.Attributes_Primary_Wisdom = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Wisdom"),
		FString("Improves perception."));


	/**
	 *
	 *	Secondary Attributes
	 */
	GameplayTags.Attributes_Secondary_ArmorClass = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.ArmorClass"), 
		FString("Reduces damage taken, improves Block Chance."));
	GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.ArmorPenetration"),
		FString("Ignores % enemy armor, increases Critical Hit Chance."));
	GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.BlockChance"),
		FString("Chance to half damage."));
	GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalHitChance"),
		FString("Chance to double damage plus critical hit bonus."));
	GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalHitDamage"),
		FString("Bonus damage from Critical Hit."));
	GameplayTags.Attributes_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.CriticalHitResistance"),
		FString("Reduces Critical Hit Chance of enemies."));
	GameplayTags.Attributes_Secondary_HealthRegen = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.HealthRegen"),
		FString("Set of Health replenishment over time."));
	GameplayTags.Attributes_Secondary_ManaRegen = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.ManaRegen"),
		FString("Set of Mana replenishment over time."));
	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxHealth"),
		FString("Calculation of total health."));
	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxMana"),
		FString("Calculation of total mana."));
	GameplayTags.Attributes_Secondary_Perception = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Perception"),
		FString("Improves visibility; improves armor penetration."));
	GameplayTags.Attributes_Secondary_Stealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Stealth"),
		FString("Calculation of character stealth."));
	GameplayTags.Attributes_Secondary_Investigation = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Investigation"),
		FString("Improves detection, chance to find invisible enemies."));
}
