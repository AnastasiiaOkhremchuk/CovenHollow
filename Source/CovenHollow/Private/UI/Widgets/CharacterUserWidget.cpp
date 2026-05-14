#include "UI/Widgets/CharacterUserWidget.h"

void UCharacterUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
