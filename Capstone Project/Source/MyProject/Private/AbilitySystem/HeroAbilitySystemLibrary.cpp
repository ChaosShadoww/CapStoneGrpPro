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
