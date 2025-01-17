// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PaperCharacterBase.h"
#include "PaperFlipbookComponent.h"
#include "AbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Sight.h"
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

	StimulusSource = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Stimulus"));
	StimulusSource->RegisterForSense(TSubclassOf<UAISense_Sight>());
	StimulusSource->RegisterWithPerceptionSystem();
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

void APaperCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void APaperCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultVitalAttributes, 1.f);
}
/* Old Init
void APaperCharacterBase::InitializePrimaryAttributes() const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(DefaultPrimaryAttributes);
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultPrimaryAttributes, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void APaperCharacterBase::InitializeSecondaryAttributes() const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(DefaultSecondaryAttributes);
	const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultSecondaryAttributes, 1.f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}
*/