#include "UI/Widgets/BaseWidget.h"

void UBaseWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
