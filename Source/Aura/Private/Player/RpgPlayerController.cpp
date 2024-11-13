// Copyright Petr Ershov


#include "Player/RpgPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Interaction/HighlightableInterface.h"

ARpgPlayerController::ARpgPlayerController()
{
	bReplicates = true;
}

void ARpgPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void ARpgPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	ThisHighlightedActor = CursorHit.GetActor();
	//both actors valid
	if (ThisHighlightedActor && LastHighlightedActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Both hit"));
		//do something only if actor changed
		if (LastHighlightedActor != ThisHighlightedActor)
		{
			LastHighlightedActor->UnhighlightActor();
			ThisHighlightedActor->HighlightActor();
			LastHighlightedActor = ThisHighlightedActor;
		}
	}
	//if only new one is hovered, highlight it
	else if (ThisHighlightedActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Only new"));
		ThisHighlightedActor->HighlightActor();
		LastHighlightedActor = ThisHighlightedActor;
	}
	//if no hover on this frame, unhighlight
	else if (LastHighlightedActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Only last"));
		LastHighlightedActor->UnhighlightActor();
		LastHighlightedActor = ThisHighlightedActor;
	}
}

void ARpgPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(PlayerContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer());
	check(Subsystem);

	Subsystem->AddMappingContext(PlayerContext, 0);
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
	
	SetActorTickEnabled(true);
}

void ARpgPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARpgPlayerController::Move);
}

void ARpgPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
