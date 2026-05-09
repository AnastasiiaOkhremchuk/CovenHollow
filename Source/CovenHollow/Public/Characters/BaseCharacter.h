#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"

#include "BaseCharacter.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class COVENHOLLOW_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "CovenHollow|GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComp;
	UPROPERTY(VisibleAnywhere, Category = "CovenHollow|GAS")
	TObjectPtr<UAttributeSet> AttributeSet;

};
