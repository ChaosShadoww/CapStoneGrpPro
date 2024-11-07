// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HeroHUD.generated.h"

class UAttributeMenuWidgetController;
class UHeroUserWidget;
class UOverlayWidgetController;
class UAbilitySystemComponent;
class UAttributeSet;
struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class MYPROJECT_API AHeroHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	

	//Function that creates the widget controller, only if it hasn't been created yet, if it has, then just return the one widget controller
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
	UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams);

	//Function to initialize the four key variables for widget controller when creating, returning widget controller in the GetOverlayWidgetController func
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);



private:

	UPROPERTY()
	TObjectPtr<UHeroUserWidget> OverlayWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UHeroUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	//UClass for GetOverlayWidgetController Function
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY()
	TObjectPtr<UAttributeMenuWidgetController> AttributeMenuWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAttributeMenuWidgetController> AttributeMenuWidgetControllerClass;
};
