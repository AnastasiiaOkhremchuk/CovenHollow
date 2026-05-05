#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"

#include "PlayerCharacter.generated.h"

class AMainPlayerController;

class USpringArmComponent;
class UCameraComponent;
class UInputAction;

struct FInputActionValue;

UCLASS()
class COVENHOLLOW_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	virtual void SetupPlayerInputComponent(UInputComponent* InPlayerInputComponent) override;

private:
	void OnMove(const FInputActionValue& InValue);
	void OnLook(const FInputActionValue& InValue);

	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|Components")
	TObjectPtr<USpringArmComponent> ArmComp;
	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|Components")
	TObjectPtr<UCameraComponent> CameraComp;

	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|EnhancedInput")
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|EnhancedInput")
	TObjectPtr<UInputAction> LookAction;
};
