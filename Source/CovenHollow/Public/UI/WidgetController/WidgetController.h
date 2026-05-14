#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "WidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class COVENHOLLOW_API UWidgetController : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category = "CovenHollow|Core")
	TObjectPtr<APlayerController> PlayerController;
	UPROPERTY(BlueprintReadOnly, Category = "CovenHollow|Core")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category = "CovenHollow|GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComp;
	UPROPERTY(BlueprintReadOnly, Category = "CovenHollow|GAS")
	TObjectPtr<UAttributeSet> AttributeSet;

};
