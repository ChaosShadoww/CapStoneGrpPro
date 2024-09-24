// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/PaperCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "HeroEnemy.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AHeroEnemy : public APaperCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	
private:
	UFUNCTION(BlueprintCallable)
	void Turn(float TurnVector);

public:
	AHeroEnemy();
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;
};
