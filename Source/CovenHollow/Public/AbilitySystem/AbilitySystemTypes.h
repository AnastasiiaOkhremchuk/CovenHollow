#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayEffectTypes.h"

#include "AbilitySystemTypes.generated.h"

USTRUCT(BlueprintType)
struct FEffectProperties
{
	GENERATED_BODY()

public:
    FEffectProperties() = default;

    FGameplayEffectContextHandle EffectContextHandle;

    UAbilitySystemComponent* SourceASC = nullptr;
    AActor* SourceActor = nullptr;
    AController* SourceController = nullptr;
    ACharacter* SourceCharacter = nullptr;

    UAbilitySystemComponent* TargetASC = nullptr;
    AActor* TargetActor = nullptr;
    AController* TargetController = nullptr;
    ACharacter* TargetCharacter = nullptr;
};
