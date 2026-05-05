#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "MainPlayerController.generated.h"

class UInputMappingContext;

UCLASS()
class COVENHOLLOW_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	void InitInputMappingContext();

	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|EnhancedInput")
	TObjectPtr<UInputMappingContext> InputMappingContext;
	
};
