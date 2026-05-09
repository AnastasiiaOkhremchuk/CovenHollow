#include "Characters/BaseEnemy.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "AbilitySystem/CharacterAttributeSet.h"

ABaseEnemy::ABaseEnemy()
{
    AbilitySystemComp = CreateDefaultSubobject<UCharacterAbilitySystemComponent>(TEXT("AbilitySystemComp"));
    AbilitySystemComp->SetIsReplicated(true);

    AttributeSet = CreateDefaultSubobject<UCharacterAttributeSet>(TEXT("AttributeSet"));
}
