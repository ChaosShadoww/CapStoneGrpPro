// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/HeroEnemy.h"
#include "PaperFlipbookComponent.h"
#include "AbilitySystem/HeroAbilitySystemComponent.h"
#include "AbilitySystem/HeroAttributeSet.h"
#include <MyProject/MyProject.h>



void AHeroEnemy::Turn(float TurnVector)
{
	if (TurnVector > 0)
	{
		HeroSprite->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	}
	if (TurnVector < 0)
	{
		HeroSprite->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	}
}

AHeroEnemy::AHeroEnemy()
{
	GetSprite()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);			//still needs test

	AbilitySystemComponent = CreateDefaultSubobject<UHeroAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UHeroAttributeSet>("AttributeSet");
	
}

void AHeroEnemy::HighlightActor()
{
	//bHighlighted = true;							//testing
	GetSprite()->SetRenderCustomDepth(true);
	GetSprite()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	
}

void AHeroEnemy::UnHighlightActor()
{
	//bHighlighted = false;
	GetSprite()->SetRenderCustomDepth(false);
	Sward->SetRenderCustomDepth(false);
	
}

int32 AHeroEnemy::GetPlayerLevel()
{
	return Level;
}

void AHeroEnemy::BeginPlay()
{
	Super::BeginPlay();

	InitAbilityActorInfo();
}

void AHeroEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UHeroAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}
