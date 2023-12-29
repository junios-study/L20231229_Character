// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TPS_PC.generated.h"


class UInputMappingContext;

/**
 * 
 */
UCLASS()
class L20231229_CHARACTER_API ATPS_PC : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data")
	TObjectPtr<UInputMappingContext> DefaultIMC;

	virtual void BeginPlay() override;
};
