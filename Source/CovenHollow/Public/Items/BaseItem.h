#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "BaseItem.generated.h"

class USphereComponent;
class UGameplayEffect;

UCLASS(Abstract)
class COVENHOLLOW_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseItem();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|Components")
	TObjectPtr<USceneComponent> SceneComp;
	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComp;
	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|Components")
	TObjectPtr<USphereComponent> SphereComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|GAS")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|GAS")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* InTarget, TSubclassOf<UGameplayEffect> InGameplayEffectClass);
};
