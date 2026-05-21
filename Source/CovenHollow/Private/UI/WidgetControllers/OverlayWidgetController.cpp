#include "UI/WidgetControllers/OverlayWidgetController.h"
#include "AbilitySystem/CharacterAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
    if (const UCharacterAttributeSet* CharacterAttributeSet = Cast<UCharacterAttributeSet>(AttributeSet))
    {
        OnHealthChanged.Broadcast(CharacterAttributeSet->GetHealth());
        OnMaxHealthChanged.Broadcast(CharacterAttributeSet->GetMaxHealth());
    }

}
