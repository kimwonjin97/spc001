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

	int32 AvgInt = Avg<int32>(1, 3);

	UE_LOG(LogTemp, Warning, TEXT("Avg of 1 and 3: %d"), AvgInt);

	float AvgFloat = Avg<float>(3.45f, 7.86f);
	UE_LOG(LogTemp, Warning, TEXT("Avg of 1 and 3: %d"), AvgFloat);

}

float AItem::TransformSine()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformCosine()
{
	return Amplitude* FMath::Cos(RunningTime * TimeConstant);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	//float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);

	//AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));

	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

	FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	DRAW_POINT_SingleFrame(AvgVector); 
}

