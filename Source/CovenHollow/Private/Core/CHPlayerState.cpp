#include "Core/CHPlayerState.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"
#include "Net/UnrealNetwork.h"

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

void ACHPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ACHPlayerState, Level);
}

void ACHPlayerState::OnRep_Level(int32 OldLevel)
{

}
