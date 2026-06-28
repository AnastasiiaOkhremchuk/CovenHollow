#include "Characters/BaseCharacter.h"
#include "AbilitySystemComponent.h"

ABaseCharacter::ABaseCharacter()
{
    PrimaryActorTick.bCanEverTick = false;

    if (USkeletalMeshComponent* SkeletalMeshComp = GetMesh())
    {
        SkeletalMeshComp->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
        SkeletalMeshComp->SetRelativeLocation(FVector(0.0f, 0.0f, -70.0f));
    }
}

void ABaseCharacter::InitAbilityActorInfo()
{

}

void ABaseCharacter::InitDefaultAttributes()
{
    ApplyEffectToSelf(DefaultPrimaryAttributesClass, 1.0f);
    ApplyEffectToSelf(DefaultSecondaryAttributesClass, 1.0f);
}

void ABaseCharacter::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level)
{
    UAbilitySystemComponent* ASC = GetAbilitySystemComponent();

    if (!ensure(ASC) || !ensure(GameplayEffectClass))
    {
        return;
    }

    const FGameplayEffectContextHandle ContextHandle = ASC->MakeEffectContext();
    const FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);

    if (SpecHandle.IsValid())
    {
        ASC->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), ASC);
    }
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
    return AbilitySystemComp;
}

