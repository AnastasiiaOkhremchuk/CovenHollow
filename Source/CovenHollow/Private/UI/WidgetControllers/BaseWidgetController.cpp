#include "UI/WidgetControllers/BaseWidgetController.h"

void UBaseWidgetController::InitWidgetControllerParams(const FWidgetControllerParams& InWidgetControllerParams)
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

void UBaseWidgetController::BroadcastInitialValues()
{
}

void UBaseWidgetController::BindCallbacksToDependencies()
{
}
