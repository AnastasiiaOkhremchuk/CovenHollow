#include "Characters/PlayerCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	ArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("ArmComp"));
	ArmComp->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	ArmComp->SetupAttachment(GetRootComponent());
	ArmComp->TargetArmLength = 200.0f;
	ArmComp->CameraLagSpeed = 10.0f;
	ArmComp->CameraRotationLagSpeed = 20.0f;
	ArmComp->CameraLagMaxDistance = 30.0f;
	ArmComp->bEnableCameraRotationLag = true;
	ArmComp->bEnableCameraLag = true;
	ArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(ArmComp);
	CameraComp->bUsePawnControlRotation = false;
}

