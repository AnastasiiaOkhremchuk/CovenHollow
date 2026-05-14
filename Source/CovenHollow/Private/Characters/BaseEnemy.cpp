#include "Characters/BaseEnemy.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "AbilitySystem/CharacterAttributeSet.h"

ABaseEnemy::ABaseEnemy()
{
    PrimaryActorTick.bCanEverTick = false;

    AbilitySystemComp = CreateDefaultSubobject<UCharacterAbilitySystemComponent>(TEXT("AbilitySystemComp"));
    AbilitySystemComp->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
    AbilitySystemComp->SetIsReplicated(true);

    AttributeSet = CreateDefaultSubobject<UCharacterAttributeSet>(TEXT("AttributeSet"));
}

void ABaseEnemy::BeginPlay()
{
    Super::BeginPlay();

    AbilitySystemComp->InitAbilityActorInfo(this, this);
}
