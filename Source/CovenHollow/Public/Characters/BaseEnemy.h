#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"

#include "BaseEnemy.generated.h"

UCLASS()
class COVENHOLLOW_API ABaseEnemy : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ABaseEnemy();

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	
};
