#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetControllers/BaseWidgetController.h"
#include "AbilitySystem/AbilitySystemTypes.h"
#include "GameplayTagContainer.h"

#include "OverlayWidgetController.generated.h"

struct FOnAttributeChangeData;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMessageWidgetRowSignature, FMessageWidgetRow, Row);

UCLASS(BlueprintType, Blueprintable)
class COVENHOLLOW_API UOverlayWidgetController : public UBaseWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category = "CovenHollow|Delegates")
	FOnAttributeChangedSignature OnHealthChanged;
	UPROPERTY(BlueprintAssignable, Category = "CovenHollow|Delegates")
	FOnAttributeChangedSignature OnMaxHealthChanged;
	UPROPERTY(BlueprintAssignable, Category = "CovenHollow|Delegates")
	FOnAttributeChangedSignature OnManaChanged;
	UPROPERTY(BlueprintAssignable, Category = "CovenHollow|Delegates")
	FOnAttributeChangedSignature OnMaxManaChanged;
	UPROPERTY(BlueprintAssignable, Category = "CovenHollow|Delegates")
	FOnAttributeChangedSignature OnStaminaChanged;
	UPROPERTY(BlueprintAssignable, Category = "CovenHollow|Delegates")
	FOnAttributeChangedSignature OnMaxStaminaChanged;
	UPROPERTY(BlueprintAssignable, Category = "CovenHollow|Delegates")
	FOnMessageWidgetRowSignature OnMessageWidgetRow;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|Data")
	TObjectPtr<UDataTable> MessageWidgetDataTable;

	template<typename T>
	T* GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag);
};

template<typename T>
inline T* UOverlayWidgetController::GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag)
{
	return DataTable->FindRow<T>(Tag.GetTagName(), TEXT(""));
}
