// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HeroPlayerController.generated.h"


class UInputMappingContext;

/**
 * 
 */
UCLASS()
class MYPROJECT_API AHeroPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AHeroPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> HeroContext;
};
