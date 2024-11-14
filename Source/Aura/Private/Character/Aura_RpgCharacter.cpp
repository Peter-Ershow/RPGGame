// Copyright Petr Ershov

#include "Character/Aura_RpgCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"

AAura_RpgCharacter::AAura_RpgCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AAura_RpgCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	//Init ability actor info for the server
	InitAbilityActorInfo();
}

void AAura_RpgCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Init ability actor info for the client
	InitAbilityActorInfo();
}

void AAura_RpgCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();
	check(AbilitySystemComponent);
	check(AttributeSet);
	
	AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState, this);
}




