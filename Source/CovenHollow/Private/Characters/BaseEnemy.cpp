#include "Characters/BaseEnemy.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"

ABaseEnemy::ABaseEnemy()
{
    PrimaryActorTick.bCanEverTick = false;

    AbilitySystemComp = CreateDefaultSubobject<UBaseAbilitySystemComponent>(TEXT("AbilitySystemComp"));
    AbilitySystemComp->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
    AbilitySystemComp->SetIsReplicated(true);

    AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>(TEXT("AttributeSet"));
}

void ABaseEnemy::BeginPlay()
{
    Super::BeginPlay();

    AbilitySystemComp->InitAbilityActorInfo(this, this);
}
