// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PaperCharacterBase.h"
#include "PaperFlipbookComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


APaperCharacterBase::APaperCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	//Spring Arm And Attachment
	HeroSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	HeroSpringArm->SetupAttachment(RootComponent);
	HeroSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(-40.0f, -90.0f, 0.0f));
	HeroSpringArm->TargetArmLength = 1000.0f;
	HeroSpringArm->bEnableCameraLag = false;
	//HeroSpringArm->CameraLagSpeed = 3.0f;																	// only if true cameralag

	// Create Camera and Setup Attachment
	HeroCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("HeroCamera"));
	//HeroCamera->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(0.0f, 0.0f, 0.0f));   //Only if no springarm
	HeroCamera->SetupAttachment(HeroSpringArm, USpringArmComponent::SocketName);
	
	//Setup Sprite Defaults
	HeroSprite->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -80.0f), FRotator(0.0f, 0.0f, -40.0f));    //GREEN,BLUE,RED
	HeroSprite->SetRelativeScale3D(FVector(4.0f, 4.0f, 4.0f));



	//Setup Sprite Component for weapon attachment
	Sward = CreateDefaultSubobject<UPaperSpriteComponent>("Sword");
	Sward->SetupAttachment(HeroSprite, FName("WeaponHandSocket"));
	Sward->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

UAbilitySystemComponent* APaperCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void APaperCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void APaperCharacterBase::InitAbilityActorInfo()
{
}
