#include "Core/CHPlayerState.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"

ACHPlayerState::ACHPlayerState()
{
	AbilitySystemComp = CreateDefaultSubobject<UBaseAbilitySystemComponent>(TEXT("AbilitySystemComp"));
	AbilitySystemComp->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AbilitySystemComp->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>(TEXT("AttributeSet"));

	NetUpdateFrequency = 100.0f;
}

UAbilitySystemComponent* ACHPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}
