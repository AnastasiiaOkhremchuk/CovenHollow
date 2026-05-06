#include "Characters/PlayerCharacter.h"
#include "Core/MainPlayerController.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	if (UCharacterMovementComponent* MovementComp = GetCharacterMovement())
	{
		MovementComp->bOrientRotationToMovement = false;
		MovementComp->RotationRate = FRotator(0.f, 540.f, 0.f);
	}

	ArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("ArmComp"));
	ArmComp->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	ArmComp->SetupAttachment(GetRootComponent());
	ArmComp->TargetArmLength = 200.0f;
	ArmComp->CameraLagSpeed = 10.0f;
	ArmComp->bEnableCameraLag = true;
	ArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(ArmComp);
	CameraComp->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

