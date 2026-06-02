#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "WidgetControllerTypes.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

public:
	FWidgetControllerParams() = default;
	FWidgetControllerParams(APlayerController* InPlayerController, APlayerState* InPlayerState, UAbilitySystemComponent* InAbilitySystemComp, UAttributeSet* InAttributeSet)
		: PlayerController(InPlayerController), PlayerState(InPlayerState), AbilitySystemComp(InAbilitySystemComp), AttributeSet(InAttributeSet) {
	}

	UPROPERTY(BlueprintReadOnly, Category = "CovenHollow|Core")
	TObjectPtr<APlayerController> PlayerController = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "CovenHollow|Core")
	TObjectPtr<APlayerState> PlayerState = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "CovenHollow|GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComp = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "CovenHollow|GAS")
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
};