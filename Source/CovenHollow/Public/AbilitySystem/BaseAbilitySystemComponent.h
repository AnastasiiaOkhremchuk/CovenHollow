#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"

#include "BaseAbilitySystemComponent.generated.h"

UCLASS()
class COVENHOLLOW_API UBaseAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void InitAbilityActorInfo();

protected:
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
	
};
