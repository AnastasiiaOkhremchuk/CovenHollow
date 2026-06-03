#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"

#include "CHPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class COVENHOLLOW_API ACHPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACHPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComp;
	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|GAS")
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
