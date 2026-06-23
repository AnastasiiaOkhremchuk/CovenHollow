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
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetHealthAttribute())
            .AddLambda([this](const FOnAttributeChangeData& Data)
            {
                OnHealthChanged.Broadcast(Data.NewValue);
            });
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetMaxHealthAttribute())
            .AddLambda([this](const FOnAttributeChangeData& Data)
            {
                OnMaxHealthChanged.Broadcast(Data.NewValue);
            });

        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetManaAttribute())
            .AddLambda([this](const FOnAttributeChangeData& Data)
            {
                OnManaChanged.Broadcast(Data.NewValue);
            });
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetMaxManaAttribute())
            .AddLambda([this](const FOnAttributeChangeData& Data)
            {
                OnMaxManaChanged.Broadcast(Data.NewValue);
            });
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetStaminaAttribute())
            .AddLambda([this](const FOnAttributeChangeData& Data)
            {
                OnStaminaChanged.Broadcast(Data.NewValue);
            });
        AbilitySystemComp->GetGameplayAttributeValueChangeDelegate(BaseAttributeSet->GetMaxStaminaAttribute())
            .AddLambda([this](const FOnAttributeChangeData& Data)
            {
                OnMaxStaminaChanged.Broadcast(Data.NewValue);
            });
    }

    if (UBaseAbilitySystemComponent* BaseAbilitySystemComponent = Cast<UBaseAbilitySystemComponent>(AbilitySystemComp))
    {
        BaseAbilitySystemComponent->GetEffectAssetTags()
            .AddLambda([this](const FGameplayTagContainer& AssetTags)
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
