// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/HeroEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

//#include "AbilitySystemInterface.h"
//#include "AbilitySystem/HeroAttributeSet.h"
//#include "Components/SphereComponent.h"


// Sets default values
AHeroEffectActor::AHeroEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	/** Removed to allow these components to be made in BP, for the designer to use as they see fit for flexibility
	* 
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());

	*/

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}





/** Removed Deprecated Code
void AHeroEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{

		//TODO: Change to apply a Gameplay Effect. For now, using const_cast as a hack
		const UHeroAttributeSet* HeroAttributeSet = Cast<UHeroAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UHeroAttributeSet::StaticClass()));
		//big no no
		UHeroAttributeSet* MutableHeroAttributeSet = const_cast<UHeroAttributeSet*>(HeroAttributeSet); //caution breaking const and encapsulation rules
		MutableHeroAttributeSet->SetHealth(HeroAttributeSet->GetHealth() + 25.f);

		MutableHeroAttributeSet->SetMana(HeroAttributeSet->GetMana() - 25.f);
		Destroy();
	}
}

void AHeroEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}


*/
// Called when the game starts or when spawned
void AHeroEffectActor::BeginPlay()
{
	Super::BeginPlay();
	//Sphere->OnComponentBeginOverlap.AddDynamic(this, &AHeroEffectActor::OnOverlap);	//DEPRECATED
	//Sphere->OnComponentEndOverlap.AddDynamic(this, &AHeroEffectActor::EndOverlap);	//DEPRECATED
}

void AHeroEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	
	/**
	//We can check if this actor has an ability system interface this way but requires to implement AbilitySystemInterface to all applicable actors
	IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(Target);
	if (ASCInterface)
	{
		ASCInterface->GetAbilitySystemComponent();		// Access to interface and asc
		//This built in function does the same as all above but also checks components and is better and doesn't need IF statement or ASCInterface^
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);					//blueprint callable
	}
	*/

	//storing AbilitySystemComponent
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr) return;

	check(GameplayEffectClass);
	//Make Context
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, ActorLevel, EffectContextHandle);
	const FActiveGameplayEffectHandle ActiveEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	const bool bIsInfinite = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite;
	if (bIsInfinite && InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		ActiveEffectHandles.Add(ActiveEffectHandle, TargetASC);
	}
}

void AHeroEffectActor::OnOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}
	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
	}
}

void AHeroEffectActor::OnEndOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}
	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
	}
	if (InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap) 
	{
		UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
		if (!IsValid(TargetASC)) return;


		TArray<FActiveGameplayEffectHandle> HandlesToRemove;
		for (auto HandlePair : ActiveEffectHandles) //TTuple<FACtiveGameplayEffectHandle,UAbilitySystemComponent*>
		{
			if (TargetASC == HandlePair.Value)
			{
				TargetASC->RemoveActiveGameplayEffect(HandlePair.Key, 1); //Removes one stack
				HandlesToRemove.Add(HandlePair.Key);
			}
		}
		for (auto& Handle : HandlesToRemove)	//FActiveGameplayEffectHandle&
		{
			ActiveEffectHandles.FindAndRemoveChecked(Handle);
		}
	}
}


