#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "MainPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

struct FInputActionValue;

UCLASS()
class COVENHOLLOW_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMainPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void InitInputMappingContext();

	void OnMove(const FInputActionValue& InValue);
	void OnLook(const FInputActionValue& InValue);

	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|EnhancedInput")
	TObjectPtr<UInputMappingContext> InputMappingContext;
	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|EnhancedInput")
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|EnhancedInput")
	TObjectPtr<UInputAction> LookAction;
};
