#include "Core/MainPlayerState.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"

AMainPlayerState::AMainPlayerState()
{
	AbilitySystemComp = CreateDefaultSubobject<UBaseAbilitySystemComponent>(TEXT("AbilitySystemComp"));
	AbilitySystemComp->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AbilitySystemComp->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>(TEXT("AttributeSet"));

	NetUpdateFrequency = 100.0f;
}

UAbilitySystemComponent* AMainPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}
