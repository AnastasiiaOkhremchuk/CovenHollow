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

	UPROPERTY()
	TObjectPtr<APlayerController> PlayerController;
	UPROPERTY()
	TObjectPtr<APlayerState> PlayerState;
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComp;
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};