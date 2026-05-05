#include "Characters/PlayerCharacter.h"
#include "Core/MainPlayerController.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"

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

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* InPlayerInputComponent)
{
	Super::SetupPlayerInputComponent(InPlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InPlayerInputComponent);
	if (!EnhancedInputComponent)
	{
		return;
	}

	if (MoveAction)
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerCharacter::OnMove);
	}
	if (LookAction)
	{
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APlayerCharacter::OnLook);
	}
}

void APlayerCharacter::OnMove(const FInputActionValue& InValue)
{
	if (!GetController())
	{
		return;
	}
	const FVector2D MoveVector = InValue.Get<FVector2D>();

	const FRotator ControlRotation = GetControlRotation();
	const FRotator YawRotation(0.0f, ControlRotation.Yaw, 0.0f);

	const FVector DirectionX = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector DirectionY = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	const FVector MoveDirection = DirectionX * MoveVector.Y + DirectionY * MoveVector.X;

	if (!MoveDirection.IsNearlyZero())
	{
		const FRotator TargetRotation = MoveDirection.Rotation();
		const FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), 10.0f);

		SetActorRotation(NewRotation);
	}
	AddMovementInput(MoveDirection);
}

void APlayerCharacter::OnLook(const FInputActionValue& InValue)
{
	if (!GetController())
	{
		return;
	}

	const FVector2D RotationVector = InValue.Get<FVector2D>();

	AddControllerYawInput(RotationVector.X);
	AddControllerPitchInput(RotationVector.Y);
}

