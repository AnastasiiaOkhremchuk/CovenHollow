#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"

#include "BaseItem.generated.h"

class UCharacterAbilitySystemComponent;

class USphereComponent;
class UParticleSystemComponent;

UENUM(BlueprintType)
enum class EEffectApplicationPolicy : uint8
{
	ApplyOnOverlap UMETA(DisplayName = "ApplyOnOverlap"),
	ApplyOnEndOverlap UMETA(DisplayName = "ApplyOnEndOverlap"),
	DoNotApply UMETA(DisplayName = "DoNotApply"),

	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EEffectRemovalPolicy : uint8
{
	RemoveOnEndOverlap UMETA(DisplayName = "RemoveOnEndOverlap"),
	DoNotRemove UMETA(DisplayName = "DoNotRemove"),

	MAX UMETA(Hidden)
};

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|Variables")
	bool bDestroyOnEffectRemoval = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|Enumerations")
	EEffectApplicationPolicy InstantEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|Enumerations")
	EEffectApplicationPolicy DurationEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|Enumerations")
	EEffectApplicationPolicy PeriodicEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|Enumerations")
	EEffectApplicationPolicy InfiniteEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CovenHollow|Enumerations")
	EEffectRemovalPolicy InfiniteEffectRemovalPolicy = EEffectRemovalPolicy::RemoveOnEndOverlap;

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
};
