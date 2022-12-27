// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SPC001Character.h"


ASPC001Character::ASPC001Character()
{

	PrimaryActorTick.bCanEverTick = true;

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

}

