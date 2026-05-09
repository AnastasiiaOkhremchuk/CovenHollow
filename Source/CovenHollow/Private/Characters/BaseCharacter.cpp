#include "Characters/BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
    PrimaryActorTick.bCanEverTick = false;

    if (USkeletalMeshComponent* SkeletalMeshComp = GetMesh())
    {
        SkeletalMeshComp->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
        SkeletalMeshComp->SetRelativeLocation(FVector(0.0f, 0.0f, -70.0f));
    }
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
    return AbilitySystemComp;
}

