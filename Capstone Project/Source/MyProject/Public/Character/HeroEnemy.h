// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/PaperCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AICombatInterface.h"
#include "HeroEnemy.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AHeroEnemy : public APaperCharacterBase, public IEnemyInterface, public IAICombatInterface
{
	GENERATED_BODY()
	
private:
	UFUNCTION(BlueprintCallable)
	void Turn(float TurnVector);

public:
	AHeroEnemy();

	/**Enemy Interface*/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/**Enemy Interface*/


	UBehaviorTree* GetBehaviorTree() const;

	/**Combat Interface**/
	virtual int32 GetPlayerLevel() override;
	/*End Combat Interface*/

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defauts")
	int32 Level = 1;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	UBehaviorTree* Tree;

};
