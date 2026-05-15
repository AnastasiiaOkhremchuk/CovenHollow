#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "BaseWidget.generated.h"

UCLASS()
class COVENHOLLOW_API UBaseWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "CovenHollow|WidgetController")
	void SetWidgetController(UObject* InWidgetController);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "CovenHollow|WidgetController")
	TObjectPtr<UObject> WidgetController;

	UFUNCTION(BlueprintImplementableEvent, Category = "CovenHollow|WidgetController")
	void WidgetControllerSet();

};