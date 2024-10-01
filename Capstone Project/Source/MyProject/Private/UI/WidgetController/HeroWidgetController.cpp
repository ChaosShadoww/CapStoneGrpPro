// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/HeroWidgetController.h"

void UHeroWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	//Pass in the data for the member variables for struct in widget controller
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UHeroWidgetController::BroadcastInitialValues()
{
}

void UHeroWidgetController::BindCallbacksToDependencies()
{
}
