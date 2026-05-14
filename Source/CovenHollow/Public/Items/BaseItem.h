#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "BaseItem.generated.h"

class USphereComponent;

UCLASS(Abstract)
class COVENHOLLOW_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseItem();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComp;
	UPROPERTY(VisibleDefaultsOnly, Category = "CovenHollow|Components")
	TObjectPtr<USphereComponent> SphereComp;

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult);
	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);
};
