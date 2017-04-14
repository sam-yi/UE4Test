// Fill out your copyright notice in the Description page of Project Settings.

#include "Escape.h"
#include "OpenDoor.h"


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

	Owner = GetOwner();

	initialRotation = Owner->GetActorRotation();

	actorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

}



// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume
	if (pressurePlate->IsOverlappingActor(actorThatOpens))
	{
		// If the ActorThatOpens is in the volume
		OpenTheDoor();
		// Log the time in which you opened the door
		lastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	// Check if the current time minus the time when we triggered the pressureplate is larger than the timedelay 1.0f;
	if (GetWorld()->GetTimeSeconds() - lastDoorOpenTime > doorCloseDelay)
	{
		CloseTheDoor();
	}

}



void UOpenDoor::OpenTheDoor()
{
	// Set the door rotation
	Owner->SetActorRotation(doorRotation);
}


void UOpenDoor::CloseTheDoor()
{
	// Sets the original door rotation
	Owner->SetActorRotation(initialRotation);
}