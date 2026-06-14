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

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

protected:
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|Components")
	TObjectPtr<USpringArmComponent> ArmComp;
	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|Components")
	TObjectPtr<UCameraComponent> CameraComp;
};
