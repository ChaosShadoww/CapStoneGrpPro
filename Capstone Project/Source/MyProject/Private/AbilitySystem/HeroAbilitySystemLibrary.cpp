// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/HeroAbilitySystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UI/WidgetController/HeroWidgetController.h"
#include "Player/HeroPlayerState.h"
#include "UI/HUD/HeroHUD.h"

UOverlayWidgetController* UHeroAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AHeroHUD* HeroHUD = Cast<AHeroHUD>(PC->GetHUD()))
		{
			AHeroPlayerState* PS = PC->GetPlayerState<AHeroPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return HeroHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UHeroAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0)) //Get player controller
	{
		if (AHeroHUD* HeroHUD = Cast<AHeroHUD>(PC->GetHUD()))								// Get the HUD
		{
			AHeroPlayerState* PS = PC->GetPlayerState<AHeroPlayerState>();					//Get the player state
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();					//Get the ability system component
			UAttributeSet* AS = PS->GetAttributeSet();										// Get the attribute set
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);			//Create the params for widget controllers
			return HeroHUD->GetAttributeMenuWidgetController(WidgetControllerParams);	// call and return widget controller getter
		}
	}
	return nullptr;
}
