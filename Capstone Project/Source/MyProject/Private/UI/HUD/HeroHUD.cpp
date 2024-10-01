// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/HeroHUD.h"

#include "UI/Widget/HeroUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AHeroHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)	//if null then create one
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);	//Create new Uobject, pass in HUD itself and UClass 
		OverlayWidgetController->SetWidgetControllerParams(WCParams);										//Key Variables set
		OverlayWidgetController->BindCallbacksToDependencies();

		return OverlayWidgetController;																		//Returns widget controller
	}
	return OverlayWidgetController;
}

void AHeroHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_HeroHUD"));							//Widget Class Check
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out BP_HeroHUD"));	// Widget Controller Check

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UHeroUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);									//Member variables for struct passed in through func
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);		//Store GetOverlayWidgetController results in pointer

	OverlayWidget->SetWidgetController(WidgetController);													//Widget's WidgetController is set 
	WidgetController->BroadcastInitialValues();


	Widget->AddToViewport();
}

