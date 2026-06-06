#include "GameplayEffects/BaseGameplayEffect.h"

#include "Components/SphereComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

ABaseGameplayEffect::ABaseGameplayEffect()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetCollisionProfileName(TEXT("NoCollision"));
	StaticMeshComp->SetupAttachment(GetRootComponent());

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetupAttachment(GetRootComponent());
}

void ABaseGameplayEffect::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseGameplayEffect::ApplyEffectToTarget(AActor* InTarget, TSubclassOf<UGameplayEffect> InGameplayEffectClass)
{
	UAbilitySystemComponent* Target = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InTarget);

	if (!Target || !ensure(InGameplayEffectClass))
	{
		return;
	}

	FGameplayEffectContextHandle EffectContextHandle = Target->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);

	const FGameplayEffectSpecHandle EffectSpecHandle = Target->MakeOutgoingSpec(InGameplayEffectClass, ActorLevel, EffectContextHandle);
	const FActiveGameplayEffectHandle ActiveEffectHandle = Target->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	const bool bIsInfinite = EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy == EGameplayEffectDurationType::Infinite;

	if (bIsInfinite && InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		ActiveEffectHandlesMap.Add(ActiveEffectHandle, Target);
	}
}

void ABaseGameplayEffect::OnOverlap(AActor* InTarget)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(InTarget, InstantGameplayEffectClass);
	}
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(InTarget, DurationGameplayEffectClass);
	}
	if (PeriodicEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(InTarget, PeriodicGameplayEffectClass);
	}
	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(InTarget, InfiniteGameplayEffectClass);
	}
}

void ABaseGameplayEffect::OnEndOverlap(AActor* InTarget)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(InTarget, InstantGameplayEffectClass);
	}
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(InTarget, DurationGameplayEffectClass);
	}
	if (PeriodicEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(InTarget, PeriodicGameplayEffectClass);
	}
	if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(InTarget, InfiniteGameplayEffectClass);
	}
	if (InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		UAbilitySystemComponent* Target = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InTarget);

		if (Target)
		{
			TArray<FActiveGameplayEffectHandle> HandlesToRemove;
			for (TTuple<FActiveGameplayEffectHandle, UAbilitySystemComponent*> Handle: ActiveEffectHandlesMap)
			{
				if (Target == Handle.Value)
				{
					Target->RemoveActiveGameplayEffect(Handle.Key, 1);
					HandlesToRemove.Add(Handle.Key);
				}
			}
			for (auto& Handle : HandlesToRemove)
			{
				ActiveEffectHandlesMap.FindAndRemoveChecked(Handle);
			}
		}
	}
}

 

