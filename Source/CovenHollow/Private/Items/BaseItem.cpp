#include "Items/BaseItem.h"
#include "AbilitySystem/CharacterAttributeSet.h"

#include "Components/SphereComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

ABaseItem::ABaseItem()
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

void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseItem::ApplyEffectToTarget(AActor* InTarget, TSubclassOf<UGameplayEffect> InGameplayEffectClass)
{
	UAbilitySystemComponent* Target = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InTarget);

	if (!Target || !ensure(InGameplayEffectClass))
	{
		return;
	}

	FGameplayEffectContextHandle EffectContextHandle = Target->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle EffectSpecHandle = Target->MakeOutgoingSpec(InGameplayEffectClass, 1.0f, EffectContextHandle);

	if (EffectSpecHandle.IsValid())
	{
		Target->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	}
}


