// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/HeroPlayerState.h"
#include <AbilitySystem/HeroAbilitySystemComponent.h>
#include <AbilitySystem/HeroAttributeSet.h>
#include <Net/UnrealNetwork.h>

AHeroPlayerState::AHeroPlayerState()
{
	NetUpdateFrequency = 100;			//How Often Server updates clients ... Replication
	AbilitySystemComponent = CreateDefaultSubobject<UHeroAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UHeroAttributeSet>("AttributeSet");
}

void AHeroPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AHeroPlayerState, Level);
}

UAbilitySystemComponent* AHeroPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AHeroPlayerState::OnRep_Level(int32 OldLevel)
{
}
