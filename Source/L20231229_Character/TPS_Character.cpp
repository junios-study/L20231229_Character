// Fill out your copyright notice in the Description page of Project Settings.


#include "TPS_Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ATPS_Character::ATPS_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
	GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0));

}

// Called when the game starts or when spawned
void ATPS_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATPS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATPS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* UEIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (UEIC)
	{
		UEIC->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &ATPS_Character::Jump);
		UEIC->BindAction(IA_Jump, ETriggerEvent::Canceled, this, &ATPS_Character::StopJumping);

		UEIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ATPS_Character::Move);
		UEIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ATPS_Character::Look);
	}

}

void ATPS_Character::Move(const FInputActionValue& Value)
{
	FVector2D Dir = Value.Get<FVector2D>();

	FRotator CameraRotaion = GetControlRotation();
	FRotator DirectionRotation = FRotator(0, CameraRotaion.Yaw, 0);

	FVector ForwardVector = UKismetMathLibrary::GetForwardVector(DirectionRotation);
	FVector RightVector = UKismetMathLibrary::GetRightVector(DirectionRotation);

	AddMovementInput(ForwardVector, Dir.Y);
	AddMovementInput(RightVector, Dir.X);
}

void ATPS_Character::Look(const FInputActionValue& Value)
{
	FVector2D Rotation = Value.Get<FVector2D>();

	AddControllerYawInput(Rotation.X);
	AddControllerPitchInput(Rotation.Y);
}
