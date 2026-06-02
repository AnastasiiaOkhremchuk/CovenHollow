#include "UI/WidgetControllers/OverlayWidgetController.h"
#include "AbilitySystem/BaseAttributeSet.h"

#include "AbilitySystemComponent.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
    if (const UBaseAttributeSet* CharacterAttributeSet = Cast<UBaseAttributeSet>(AttributeSet))
    {
        OnHealthChanged.Broadcast(CharacterAttributeSet->GetHealth());
        OnMaxHealthChanged.Broadcast(CharacterAttributeSet->GetMaxHealth());
        OnManaChanged.Broadcast(CharacterAttributeSet->GetMana());
        OnMaxManaChanged.Broadcast(CharacterAttributeSet->GetMaxMana());
        OnStaminaChanged.Broadcast(CharacterAttributeSet->GetStamina());
        OnMaxStaminaChanged.Broadcast(CharacterAttributeSet->GetMaxStamina());
    }
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
    if (const UBaseAttributeSet* CharacterAttributeSet = Cast<UBaseAttributeSet>(AttributeSet))
    {
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(CharacterAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(CharacterAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(CharacterAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(CharacterAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(CharacterAttributeSet->GetStaminaAttribute()).AddUObject(this, &UOverlayWidgetController::StaminaChanged);
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(CharacterAttributeSet->GetMaxStaminaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxStaminaChanged);
    }
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
    OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
    OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
    OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
    OnMaxManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::StaminaChanged(const FOnAttributeChangeData& Data) const
{
    OnStaminaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxStaminaChanged(const FOnAttributeChangeData& Data) const
{
    OnMaxStaminaChanged.Broadcast(Data.NewValue);
}
