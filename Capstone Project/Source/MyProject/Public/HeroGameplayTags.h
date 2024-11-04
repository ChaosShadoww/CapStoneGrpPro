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

protected:

private:
	//Instance variable
	static FHeroGameplayTags GameplayTags;
};