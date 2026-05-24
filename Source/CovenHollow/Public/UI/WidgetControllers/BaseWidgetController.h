#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "BaseWidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

public:
	FWidgetControllerParams() = default;
	FWidgetControllerParams(APlayerController* InPlayerController, APlayerState* InPlayerState, UAbilitySystemComponent* InAbilitySystemComp, UAttributeSet* InAttributeSet)
		: PlayerController(InPlayerController), PlayerState(InPlayerState), AbilitySystemComp(InAbilitySystemComp), AttributeSet(InAttributeSet){}

	UPROPERTY(BlueprintReadOnly, Category = "CovenHollow|Core")
	TObjectPtr<APlayerController> PlayerController = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "CovenHollow|Core")
	TObjectPtr<APlayerState> PlayerState = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "CovenHollow|GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComp = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "CovenHollow|GAS")
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
};

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
