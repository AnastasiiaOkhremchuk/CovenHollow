#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"

#include "MainPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class COVENHOLLOW_API AMainPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AMainPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "CovenHollow|GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComp;
	UPROPERTY(VisibleAnywhere, Category = "CovenHollow|GAS")
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
