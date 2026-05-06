#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"

#include "PlayerCharacter.generated.h"

class AMainPlayerController;

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class COVENHOLLOW_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

private:
	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|Components")
	TObjectPtr<USpringArmComponent> ArmComp;
	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|Components")
	TObjectPtr<UCameraComponent> CameraComp;
};
