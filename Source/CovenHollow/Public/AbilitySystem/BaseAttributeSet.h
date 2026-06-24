#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemTypes.h"

#include "BaseAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class COVENHOLLOW_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UBaseAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attrubute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Health)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxHealth)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Mana)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxMana)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Stamina)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxStamina)

	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Strength)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Intelligence)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Resilience)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Vigor)

protected:

	/*
	* Vital attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "CovenHollow|VitalAttributes")
	FGameplayAttributeData Health;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "CovenHollow|VitalAttributes")
	FGameplayAttributeData MaxHealth;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "CovenHollow|VitalAttributes")
	FGameplayAttributeData Mana;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "CovenHollow|VitalAttributes")
	FGameplayAttributeData MaxMana;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "CovenHollow|VitalAttributes")
	FGameplayAttributeData Stamina;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "CovenHollow|VitalAttributes")
	FGameplayAttributeData MaxStamina;

	/*
	* Primary attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "CovenHollow|PrimaryAttributes")
	FGameplayAttributeData Strength;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "CovenHollow|PrimaryAttributes")
	FGameplayAttributeData Intelligence;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resilience, Category = "CovenHollow|PrimaryAttributes")
	FGameplayAttributeData Resilience;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vigor, Category = "CovenHollow|PrimaryAttributes")
	FGameplayAttributeData Vigor;

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth);
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana);
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina);
	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina);

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength);
	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence);
	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience);
	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor);

private:
	void InitEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
	
};
