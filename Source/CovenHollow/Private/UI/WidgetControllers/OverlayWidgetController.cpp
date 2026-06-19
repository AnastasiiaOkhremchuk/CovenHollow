#include "UI/WidgetControllers/OverlayWidgetController.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"

#include "AbilitySystemComponent.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
    if (const UBaseAttributeSet* BaseAttributeSet = Cast<UBaseAttributeSet>(AttributeSet))
    {
        OnHealthChanged.Broadcast(BaseAttributeSet->GetHealth());
        OnMaxHealthChanged.Broadcast(BaseAttributeSet->GetMaxHealth());
        OnManaChanged.Broadcast(BaseAttributeSet->GetMana());
        OnMaxManaChanged.Broadcast(BaseAttributeSet->GetMaxMana());
        OnStaminaChanged.Broadcast(BaseAttributeSet->GetStamina());
        OnMaxStaminaChanged.Broadcast(BaseAttributeSet->GetMaxStamina());
    }
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
    if (const UBaseAttributeSet* BaseAttributeSet = Cast<UBaseAttributeSet>(AttributeSet))
    {
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetStaminaAttribute()).AddUObject(this, &UOverlayWidgetController::StaminaChanged);
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetMaxStaminaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxStaminaChanged);
    }

    if (UBaseAbilitySystemComponent* BaseAbilitySystemComponent = Cast<UBaseAbilitySystemComponent>(AbilitySystemComp))
    {
        BaseAbilitySystemComponent->GetEffectAssetTags().AddLambda([this](const FGameplayTagContainer& AssetTags)
        {
            for (const FGameplayTag& Tag : AssetTags)
            {
                FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
                if(Tag.MatchesTag(MessageTag))
                {
                    const FMessageWidgetRow* Row = GetDataTableRowByTag<FMessageWidgetRow>(MessageWidgetDataTable, Tag);
                    OnMessageWidgetRow.Broadcast(*Row);
                }
            }
        });
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
