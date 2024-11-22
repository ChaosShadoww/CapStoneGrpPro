// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "MyBTService_ChangeSpeed.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyBTService_ChangeSpeed : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UMyBTService_ChangeSpeed();
	//virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, unit8* NodeMemory) override;
};

