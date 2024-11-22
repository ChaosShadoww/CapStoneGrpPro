// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NPC_ORIGIN.h"

// Sets default values
ANPC_ORIGIN::ANPC_ORIGIN()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPC_ORIGIN::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC_ORIGIN::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC_ORIGIN::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

