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

	virtual int32 GetCharacterLevel() override;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CovenHollow|Properties")
	int32 Level = 1;
	
};
