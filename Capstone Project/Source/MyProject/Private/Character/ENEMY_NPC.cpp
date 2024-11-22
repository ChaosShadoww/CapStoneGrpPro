// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ENEMY_NPC.h"

// Sets default values
AENEMY_NPC::AENEMY_NPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AENEMY_NPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AENEMY_NPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AENEMY_NPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

