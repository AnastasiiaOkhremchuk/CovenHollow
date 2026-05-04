#include "Characters/BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
    PrimaryActorTick.bCanEverTick = false;

    USkeletalMeshComponent* SkeletalMeshComp = GetMesh();

    if (SkeletalMeshComp)
    {
        SkeletalMeshComp->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
        SkeletalMeshComp->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
    }
}

