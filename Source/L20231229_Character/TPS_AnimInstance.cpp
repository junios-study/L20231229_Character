// Fill out your copyright notice in the Description page of Project Settings.


#include "TPS_AnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UTPS_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	ACharacter* Pawn = Cast<ACharacter>(TryGetPawnOwner());

	if (IsValid(Pawn))
	{
		GroundSpeed = Pawn->GetCharacterMovement()->Velocity.Size2D();
		ShouldMove = (GroundSpeed > 3.0f) && UKismetMathLibrary::NotEqual_VectorVector(Pawn->GetCharacterMovement()->GetCurrentAcceleration(), FVector::ZeroVector, 0);
		IsFalling = Pawn->GetCharacterMovement()->IsFalling();
	}

}
