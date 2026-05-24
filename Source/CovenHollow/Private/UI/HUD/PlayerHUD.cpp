#include "UI/HUD/PlayerHUD.h"
#include "UI/Widgets/BaseWidget.h"
#include "UI/WidgetControllers/OverlayWidgetController.h"

void APlayerHUD::InitOverlayWidget(APlayerController* InPlayerController, APlayerState* InPlayerState, UAbilitySystemComponent* InAbilitySystemComp, UAttributeSet* InAttributeSet)
{
	if (!ensure(OverlayWidgetClass) || !ensure(OverlayWidgetControllerClass))
	{
		return;
	}

	const FWidgetControllerParams WidgetControllerParams(InPlayerController, InPlayerState, InAbilitySystemComp, InAttributeSet);

	OverlayWidget = CreateWidget<UBaseWidget>(GetWorld(), OverlayWidgetClass);
	check(OverlayWidget);

	OverlayWidget->SetWidgetController(GetOverlayWidgetController(WidgetControllerParams));
	OverlayWidgetController->BroadcastInitialValues();
	OverlayWidget->AddToViewport();
}

UOverlayWidgetController* APlayerHUD::GetOverlayWidgetController(const FWidgetControllerParams& InWidgetControllerParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->InitWidgetControllerParams(InWidgetControllerParams);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}
