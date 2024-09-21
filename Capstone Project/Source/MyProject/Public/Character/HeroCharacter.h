// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/PaperCharacterBase.h"
#include "HeroCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AHeroCharacter : public APaperCharacterBase
{
	GENERATED_BODY()
	
private:
	UFUNCTION(BlueprintCallable)
	void Turn(float TurnVector);
};
