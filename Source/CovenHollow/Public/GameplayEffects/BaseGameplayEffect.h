#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "BaseGameplayEffectTypes.h"

#include "BaseGameplayEffect.generated.h"

class USphereComponent;
class UParticleSystemComponent;

UCLASS(Abstract)
class COVENHOLLOW_API ABaseGameplayEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseGameplayEffect();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|Components")
	TObjectPtr<USceneComponent> SceneComp;
	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComp;
	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|Components")
	TObjectPtr<USphereComponent> SphereComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|Properties")
	bool bDestroyOnEffectRemoval = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|Properties")
	float ActorLevel = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|Effects")
	TSubclassOf<UGameplayEffect> PeriodicGameplayEffectClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|Effects")
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* InTarget, TSubclassOf<UGameplayEffect> InGameplayEffectClass);
	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* InTarget);
	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* InTarget);

private:
	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandlesMap;

	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|Enumerations")
	EEffectApplicationPolicy InstantEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|Enumerations")
	EEffectApplicationPolicy DurationEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|Enumerations")
	EEffectApplicationPolicy PeriodicEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|Enumerations")
	EEffectApplicationPolicy InfiniteEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	UPROPERTY(EditDefaultsOnly, Category = "CovenHollow|Enumerations")
	EEffectRemovalPolicy InfiniteEffectRemovalPolicy = EEffectRemovalPolicy::RemoveOnEndOverlap;
};
