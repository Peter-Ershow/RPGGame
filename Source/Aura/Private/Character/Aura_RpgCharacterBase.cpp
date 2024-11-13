// Copyright Petr Ershov

#include "Character/Aura_RpgCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"

AAura_RpgCharacterBase::AAura_RpgCharacterBase()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}
