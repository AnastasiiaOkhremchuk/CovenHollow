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
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

	FORCEINLINE int32 GetCharacterLevel() const { return Level; }

protected:
	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComp;
	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|GAS")
	TObjectPtr<UAttributeSet> AttributeSet;
	
private:
	UPROPERTY(VisibleDefaultsOnly, ReplicatedUsing = OnRep_Level, Category = "CovenHollow|Properties")
	int32 Level = 1;

	UFUNCTION()
	void OnRep_Level(int32 OldLevel);
};
