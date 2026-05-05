#include "Core/MainPlayerController.h"
#include "Characters/PlayerCharacter.h"

#include "EnhancedInputSubsystems.h"

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	InitInputMappingContext();
}

void AMainPlayerController::InitInputMappingContext()
{
    if (!IsLocalController() || !InputMappingContext)
    {
        return;
    }

    ULocalPlayer* LocalPlayer = GetLocalPlayer();
    if (!LocalPlayer)
    {
        return;
    }

    if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
    {
        InputSubsystem->AddMappingContext(InputMappingContext, 0);
    }
}
