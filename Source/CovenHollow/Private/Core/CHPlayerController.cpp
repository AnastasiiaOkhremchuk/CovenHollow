#include "Core/CHPlayerController.h"
#include "Characters/PlayerCharacter.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

ACHPlayerController::ACHPlayerController()
{
    bReplicates = true;
}

void ACHPlayerController::BeginPlay()
{
	Super::BeginPlay();

	InitInputMappingContext();
}

void ACHPlayerController::InitInputMappingContext()
{
	if (!IsLocalController() || !ensure(InputMappingContext))
	{
		return;
	}

	ULocalPlayer* LocalPlayer = GetLocalPlayer();
	check(LocalPlayer);

	if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
	{
		InputSubsystem->AddMappingContext(InputMappingContext, 0);
	}
}

void ACHPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	if (ensure(MoveAction))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACHPlayerController::OnMove);
	}
	if (ensure(LookAction))
	{
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACHPlayerController::OnLook);
	}
}

void ACHPlayerController::OnMove(const FInputActionValue& InValue)
{
	APawn* ControlledPawn = GetPawn<APawn>();
	if (!ControlledPawn)
	{
		return;
	}

    const FVector2D MoveVector = InValue.Get<FVector2D>();

	const FRotator YawRotation(0.0f, GetControlRotation().Yaw, 0.0f);

	const FRotationMatrix RotMatrix(YawRotation);
	const FVector DirectionX = RotMatrix.GetUnitAxis(EAxis::X);
	const FVector DirectionY = RotMatrix.GetUnitAxis(EAxis::Y);

	const FVector MoveDirection = DirectionX * MoveVector.Y + DirectionY * MoveVector.X;

	const FRotator TargetRotation = MoveDirection.Rotation();
	const FRotator NewRotation = FMath::RInterpTo(ControlledPawn->GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), 10.0f);

	ControlledPawn->SetActorRotation(NewRotation);
	ControlledPawn->AddMovementInput(MoveDirection);
}

void ACHPlayerController::OnLook(const FInputActionValue& InValue)
{
	const FVector2D RotationVector = InValue.Get<FVector2D>();

	AddYawInput(RotationVector.X);
	AddPitchInput(RotationVector.Y);
}
