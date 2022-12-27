// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SPC001Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ASPC001Character::ASPC001Character()
{

	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);


	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 300.f;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(CameraBoom);
}


void ASPC001Character::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.f))
	{
		//find out which way is forward.
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ASPC001Character::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.f))
	{
		//find out which way is right
		const FRotator ControlRotation = GetControlRotation();
		const FRotator YawRotation(0.f, ControlRotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void ASPC001Character::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ASPC001Character::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void ASPC001Character::BeginPlay()
{
	Super::BeginPlay();
	
}


void ASPC001Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ASPC001Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ASPC001Character::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ASPC001Character::MoveRight);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ASPC001Character::Turn);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ASPC001Character::LookUp);

}

