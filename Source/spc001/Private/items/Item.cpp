// Fill out your copyright notice in the Description page of Project Settings.


#include "items/Item.h"
#include "spc001/DebugMacros.h"



AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
}


void AItem::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Movement rate is units of cm/s
	float MovementRate = 50.f;
	float RotationRate = 45.f;

	// MovementRate * DeltaTime(cm/s) * (s/frame) = (cm/frame)
	AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
	AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));
	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);
}

