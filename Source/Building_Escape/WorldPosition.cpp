// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldPosition.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorldPosition::UWorldPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();

	// ...

	//UE_LOG(LogTemp, Warning, TEXT("This is a Warning"));
	//UE_LOG(LogTemp, Error, TEXT("This is a Error"));
	//UE_LOG(LogTemp, Display, TEXT("This is a Display"));

	// FString Log = TEXT("Hello!");
	// FString* PtrLog = &Log;		
	
	// UE_LOG(LogTemp, Warning, TEXT("%s"), **PtrLog);

	// UE_LOG(LogTemp, Warning, TEXT("%i"), Log.Len());

	// UE_LOG(LogTemp, Warning, TEXT("%i"), (*PtrLog).Len());

	// UE_LOG(LogTemp, Warning, TEXT("%i"), PtrLog->Len());

	AActor* Actor = GetOwner();
	FString ObjectName = Actor->GetName();
	FString ObjectPosition = GetOwner()->GetActorLocation().ToCompactString();

	UE_LOG(LogTemp, Warning, TEXT("The object name is %s"), * ObjectName);
	UE_LOG(LogTemp, Warning, TEXT("The object position is %s"), * ObjectPosition);
}


// Called every frame
void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

