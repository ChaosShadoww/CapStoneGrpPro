// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HeroUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UHeroUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	//Sets Widget Controller
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)												//~ Tied with WidgetControllerSet Function
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)										//~ Begin play type function
	void WidgetControllerSet();
};
