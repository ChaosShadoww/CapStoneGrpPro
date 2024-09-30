// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/HeroEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/HeroAttributeSet.h"
#include "Components/SphereComponent.h"


// Sets default values
AHeroEffectActor::AHeroEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());

}

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

// Called when the game starts or when spawned
void AHeroEffectActor::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AHeroEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AHeroEffectActor::EndOverlap);
}


