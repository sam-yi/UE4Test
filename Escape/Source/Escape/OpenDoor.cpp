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

	initialRotation = GetOwner()->GetActorRotation();

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
	}
	else
	{
		// If the ActorThatOpens is outside of the volume
		CloseTheDoor();
	}
}


void UOpenDoor::OpenTheDoor()
{
	// Find the owning Actor
	AActor* Owner = GetOwner();

	// Create a rotator
	FRotator NewRotation = FRotator(0.0f, -180.0f, 0.0f);

	// Set the door rotation
	Owner->SetActorRotation(NewRotation);
}


void UOpenDoor::CloseTheDoor()
{
	// Finds the owning Actor
	AActor* Owner = GetOwner();

	// Sets the original door rotation
	Owner->SetActorRotation(initialRotation);
}