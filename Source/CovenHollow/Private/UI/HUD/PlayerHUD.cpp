#include "UI/HUD/PlayerHUD.h"
#include "UI/Widgets/BaseWidget.h"

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	InitOverlayWidget();
}

void APlayerHUD::InitOverlayWidget()
{
	if (ensure(OverlayWidgetClass))
	{
		UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
		Widget->AddToViewport();
	}
}
