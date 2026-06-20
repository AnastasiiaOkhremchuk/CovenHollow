#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayEffectTypes.h"

#include "AbilitySystemTypes.generated.h"

class UBaseWidget;

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

USTRUCT(BlueprintType)
struct FMessageWidgetRow : public FTableRowBase
{
    GENERATED_BODY()

public:
    FMessageWidgetRow() = default;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|MessageWidgetRow")
    FGameplayTag MessageTag;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|MessageWidgetRow")
    FText Message;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|MessageWidgetRow")
    TObjectPtr<UTexture2D> Icon;
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|MessageWidgetRow")
    TSubclassOf<UBaseWidget> MessageWidgetClass;
};
