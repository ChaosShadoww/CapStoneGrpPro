// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/PaperCharacterBase.h"
#include "Player/HeroPlayerState.h"
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

	virtual void InitAbilityActorInfo() override;



	//class UAIPerceptionStimuliSourceComponent* StimulusSource;
	//void SetupStimulusSource();

public:
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	/*Combat Interface*/
	virtual int32 GetPlayerLevel() override;
	/*End Combat Interface*/
	


};
