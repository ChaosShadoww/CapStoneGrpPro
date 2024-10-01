// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/HeroAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	//delegates for broadcasting values
	//OnHealthChanged.Broadcast(100.f); This is hardcoded
	const UHeroAttributeSet* HeroAttributeSet = CastChecked<UHeroAttributeSet>(AttributeSet);


	/**** Here we are Raising the Events from Overlay Widget Controller ****/

	OnHealthChanged.Broadcast(HeroAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(HeroAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(HeroAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(HeroAttributeSet->GetMaxMana());

	//AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HeroAttributeSet->GetHealthAttribute()).AddUObject(this, )
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UHeroAttributeSet* HeroAttributeSet = CastChecked<UHeroAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		HeroAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		HeroAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		HeroAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		HeroAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
