#include "UI/WidgetControllers/OverlayWidgetController.h"
#include "AbilitySystem/CharacterAttributeSet.h"

#include "AbilitySystemComponent.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
    if (const UCharacterAttributeSet* CharacterAttributeSet = Cast<UCharacterAttributeSet>(AttributeSet))
    {
        OnHealthChanged.Broadcast(CharacterAttributeSet->GetHealth());
        OnMaxHealthChanged.Broadcast(CharacterAttributeSet->GetMaxHealth());
    }
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
    if (const UCharacterAttributeSet* CharacterAttributeSet = Cast<UCharacterAttributeSet>(AttributeSet))
    {
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(CharacterAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(CharacterAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
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
