// Fill out your copyright notice in the Description page of Project Settings.


#include "TPS_PC.h"

#include "EnhancedInputSubsystems.h"

void ATPS_PC::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem< UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (SubSystem && DefaultIMC)
	{
		SubSystem->AddMappingContext(DefaultIMC, 0);
	}
}
