#include "UI/WidgetController/WidgetController.h"

void UWidgetController::InitWidgetControllerParams(const FWidgetControllerParams& InWidgetControllerParams)
{
	check(InWidgetControllerParams.PlayerController);
	check(InWidgetControllerParams.PlayerState);
	check(InWidgetControllerParams.AbilitySystemComp);
	check(InWidgetControllerParams.AttributeSet);

	PlayerController = InWidgetControllerParams.PlayerController;
	PlayerState = InWidgetControllerParams.PlayerState;
	AbilitySystemComp = InWidgetControllerParams.AbilitySystemComp;
	AttributeSet = InWidgetControllerParams.AttributeSet;
}
