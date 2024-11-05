// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroAssetManager.h"
#include "HeroGameplayTags.h"

UHeroAssetManager& UHeroAssetManager::Get()
{
	// TODO: insert return statement here
	check(GEngine);
	UHeroAssetManager* HeroAssetManager = Cast<UHeroAssetManager>(GEngine->AssetManager);
	return *HeroAssetManager;

}

void UHeroAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FHeroGameplayTags::InitializeNativeGameplayTags();
}
