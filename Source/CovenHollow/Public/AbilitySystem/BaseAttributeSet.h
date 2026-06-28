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

	/*
	* Vital attributes
	*/

	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Health)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Mana)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Stamina)

	/*
	* Primary attributes
	*/

	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Strength)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Intelligence)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Resilience)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Vigor)

	/*
	* Secondary attributes
	*/

	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxHealth)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxMana)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxStamina)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Armor)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, ArmorPenetration)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, BlockChance)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, CriticalHitChance)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, CriticalHitResistance)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, HealthRegeneration)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, ManaRegeneration)
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, StaminaRegeneration)

protected:

	/*
	* Vital attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "CovenHollow|VitalAttributes")
	FGameplayAttributeData Health;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "CovenHollow|VitalAttributes")
	FGameplayAttributeData Mana;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "CovenHollow|VitalAttributes")
	FGameplayAttributeData Stamina;

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

	/*
	* Secondary attributes
	*/

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "CovenHollow|SecondaryAttributes")
	FGameplayAttributeData MaxHealth;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "CovenHollow|SecondaryAttributes")
	FGameplayAttributeData MaxMana;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "CovenHollow|SecondaryAttributes")
	FGameplayAttributeData MaxStamina;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "CovenHollow|SecondaryAttributes")
	FGameplayAttributeData Armor;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArmorPenetration, Category = "CovenHollow|SecondaryAttributes")
	FGameplayAttributeData ArmorPenetration;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockChance, Category = "CovenHollow|SecondaryAttributes")
	FGameplayAttributeData BlockChance;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitChance, Category = "CovenHollow|SecondaryAttributes")
	FGameplayAttributeData CriticalHitChance;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitResistance, Category = "CovenHollow|SecondaryAttributes")
	FGameplayAttributeData CriticalHitResistance;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegeneration, Category = "CovenHollow|SecondaryAttributes")
	FGameplayAttributeData HealthRegeneration;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRegeneration, Category = "CovenHollow|SecondaryAttributes")
	FGameplayAttributeData ManaRegeneration;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_StaminaRegeneration, Category = "CovenHollow|SecondaryAttributes")
	FGameplayAttributeData StaminaRegeneration;

	/*
	* Vital attributes
	*/

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth);
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana);
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina);

	/*
	* Primary attributes
	*/

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength);
	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence);
	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience);
	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor);

	/*
	* Secondary attributes
	*/

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);
	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina);
	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor);
	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration);
	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance);
	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance);
	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance);
	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration);
	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration);
	UFUNCTION()
	void OnRep_StaminaRegeneration(const FGameplayAttributeData& OldStaminaRegeneration);

private:
	void InitEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
	
};
