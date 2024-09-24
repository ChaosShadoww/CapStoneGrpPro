// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HeroPlayerController.generated.h"


class UInputMappingContext;				//forward declared
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;

/**
 * 
 */
UCLASS()
class MYPROJECT_API AHeroPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AHeroPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> HeroContext;			//IMC Blueprint forward declare, also add to module names in target.cs build file (input)

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;
	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();

	//Incorrect way to use interface, you need special wrapper, see below
	//IEnemyInterface* LastActor;
	//IEnemyInterface* ThisActor;
	//Correct Way VVVV
	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;
};
