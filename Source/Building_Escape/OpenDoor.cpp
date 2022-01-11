// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	//FRotator CurrentRotation = GetOwner()->GetActorRotation();
	//CurrentRotation.Yaw = 0.0f;
	//FRotator OpenDoor = {0.0f, 90.0f, 0.0f};
	//FRotator OpenDoor {0.0f, 90.0f, 0.0f};
	//FRotator OpenDoor = FRotator(0.0f, 0.0f, 0.0f);
	//FRotator OpenDoor (0.0f, 45.0f, 0.0f);

	//GetOwner()->SetActorRotation(CurrentRotation);

	this->InitialYaw = GetOwner()->GetActorRotation().Yaw;
	this->CurrentYaw = this->InitialYaw;
	//this->TargetOpenYaw = this->InitialYaw + 90.0f;
	this->TargetOpenYaw += this->InitialYaw;
	this->TargetCloseYaw = this->InitialYaw;
	this->DoorOpened = false;
	this->DoorClosed = true;
	this->DoorAction = false;
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!this->DoorAction && !this->DoorOpened)
	{
		this->OpenDoor(DeltaTime);
	}
	if (!this->DoorAction && !this->DoorClosed)
	{
		this->CloseDoor(DeltaTime);
	}	
	
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	//UE_LOG(LogTemp, Warning, TEXT("Opening door"));
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorForwardVector().ToString());	
	//UE_LOG(LogTemp, Warning, TEXT("%f"), GetOwner()->GetActorRotation().Yaw);

	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	//CurrentRotation.Yaw = FMath::Lerp(CurrentRotation.Yaw, this->TargetOpenYaw, 0.01f); // DEPENDE DA TAXA DE QUADROS

	// DUAS MANEIRAS DE INTERPOLAR VALORES COM O TEMPO
	this->CurrentYaw = FMath::FInterpConstantTo(CurrentRotation.Yaw, this->TargetOpenYaw, DeltaTime, 45.0F); // DEPENDE DO TEMPO E NÃO DA TAXA DE QUADORS
	//this->CurrentYaw = FMath::FInterpTo(CurrentRotation.Yaw, this->TargetOpenYaw, DeltaTime, 2.0F); // DEPENDE DO TEMPO E NÃO DA TAXA DE QUADORS
	CurrentRotation.Yaw = this->CurrentYaw;

	if (CurrentRotation.Yaw == this->TargetOpenYaw) {
		this->DoorClosed = false;
		this->DoorOpened = true;
		this->DoorAction = false;
	}

	GetOwner()->SetActorRotation(CurrentRotation);	
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
	//UE_LOG(LogTemp, Warning, TEXT("Closing door"));
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorForwardVector().ToString());	
	//UE_LOG(LogTemp, Warning, TEXT("%f"), GetOwner()->GetActorRotation().Yaw);

	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	//CurrentRotation.Yaw = FMath::Lerp(CurrentRotation.Yaw, this->TargetCloseYaw, 0.01f); // DEPENDE DA TAXA DE QUADROS

	// DUAS MANEIRAS DE INTERPOLAR VALORES COM O TEMPO
	this->CurrentYaw = FMath::FInterpConstantTo(CurrentRotation.Yaw, this->TargetCloseYaw, DeltaTime, 45.0F); // DEPENDE DO TEMPO E NÃO DA TAXA DE QUADORS
	//this->CurrentYaw = FMath::FInterpTo(CurrentRotation.Yaw, this->TargetCloseYaw, DeltaTime, 2.0F); // DEPENDE DO TEMPO E NÃO DA TAXA DE QUADORS
	CurrentRotation.Yaw = this->CurrentYaw;

	if (CurrentRotation.Yaw == this->TargetCloseYaw) {
		this->DoorClosed = true;
		this->DoorOpened = false;
		this->DoorAction = false;
	}

	GetOwner()->SetActorRotation(CurrentRotation);	
}