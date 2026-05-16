#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "PlayerHUD.generated.h"

class UBaseWidget;

UCLASS()
class COVENHOLLOW_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	void InitOverlayWidget();

	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|UI")
	TObjectPtr<UBaseWidget> OverlayWidget;

	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|UI")
	TSubclassOf<UBaseWidget> OverlayWidgetClass;
};
