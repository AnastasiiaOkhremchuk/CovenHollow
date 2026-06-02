#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WidgetControllerTypes.h"

#include "BaseWidgetController.generated.h"

UCLASS()
class COVENHOLLOW_API UBaseWidgetController : public UObject
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues();
	virtual void BindCallbacksToDependencies();

	UFUNCTION(BlueprintCallable)
	void InitWidgetControllerParams(const FWidgetControllerParams& InWidgetControllerParams);

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
