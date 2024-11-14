// Copyright Petr Ershov
#include "Character/RpgCharacterBase.h"

ARpgCharacterBase::ARpgCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* ARpgCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ARpgCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void ARpgCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

