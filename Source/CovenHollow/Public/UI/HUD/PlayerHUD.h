#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/WidgetControllers/BaseWidgetController.h"

#include "PlayerHUD.generated.h"

class UBaseWidget;
class UOverlayWidgetController;

struct FWidgetControllerParams;

UCLASS()
class COVENHOLLOW_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& InWidgetControllerParams);

private:
	void InitOverlayWidget(APlayerController* InPlayerController, APlayerState* InPlayerState, UAbilitySystemComponent* InAbilitySystemComp, UAttributeSet* InAttributeSet);

	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|UI")
	TObjectPtr<UBaseWidget> OverlayWidget;
	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|UI")
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|UI")
	TSubclassOf<UBaseWidget> OverlayWidgetClass;
	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|UI")
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
