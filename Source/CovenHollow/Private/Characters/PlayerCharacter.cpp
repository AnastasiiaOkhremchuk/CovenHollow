#include "Characters/PlayerCharacter.h"
#include "Core/CHPlayerController.h"
#include "Core/CHPlayerState.h"
#include "UI/HUD/PlayerHUD.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "AbilitySystemComponent.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	if (UCharacterMovementComponent* MovementComp = GetCharacterMovement())
	{
		MovementComp->bOrientRotationToMovement = false;
		MovementComp->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	}

	ArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("ArmComp"));
	ArmComp->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	ArmComp->SetupAttachment(GetRootComponent());
	ArmComp->TargetArmLength = 200.0f;
	ArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(ArmComp);
	CameraComp->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilityActorInfo();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilityActorInfo();
}

void APlayerCharacter::InitAbilityActorInfo()
{
	ACHPlayerState* CHPlayerState = GetPlayerState<ACHPlayerState>();
	check(CHPlayerState);

	CHPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(CHPlayerState, this);
	AbilitySystemComp = CHPlayerState->GetAbilitySystemComponent();
	AttributeSet = CHPlayerState->GetAttributeSet();

	if (ACHPlayerController* CHPlayerController = Cast<ACHPlayerController>(GetController()))
	{
		if (APlayerHUD* PlayerHUD = Cast<APlayerHUD>(CHPlayerController->GetHUD()))
		{
			PlayerHUD->InitOverlayWidget(CHPlayerController, CHPlayerState, AbilitySystemComp, AttributeSet);
		}
	}
}

