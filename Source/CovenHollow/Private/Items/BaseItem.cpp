#include "Items/BaseItem.h"
#include "AbilitySystem/CharacterAttributeSet.h"

#include "Components/SphereComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"

ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	SetRootComponent(StaticMeshComp);

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetupAttachment(GetRootComponent());
}

void ABaseItem::BeginPlay()
{
	Super::BeginPlay();

	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ABaseItem::OnOverlapBegin);
	SphereComp->OnComponentEndOverlap.AddDynamic(this, &ABaseItem::OnOverlapEnd);
}

void ABaseItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: Change this to apply a Gameplay Effect.

	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UCharacterAttributeSet* CharacterAttributeSet = Cast<UCharacterAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UCharacterAttributeSet::StaticClass()));
		UCharacterAttributeSet* MutableCharacterAttributeSet = const_cast<UCharacterAttributeSet*>(CharacterAttributeSet);
		MutableCharacterAttributeSet->SetHealth(CharacterAttributeSet->GetHealth() + 25.0f);

		Destroy();
	}
}

void ABaseItem::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{

}


