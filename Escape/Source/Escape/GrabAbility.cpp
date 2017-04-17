// Fill out your copyright notice in the Description page of Project Settings.

#include "Escape.h"
#include "GrabAbility.h"

#define OUT // This is a self made blank MACRO that does nothing at all other than inform us that we are using an OUT parameter


// Sets default values for this component's properties
UGrabAbility::UGrabAbility()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabAbility::BeginPlay()
{
	Super::BeginPlay();

	// ...

	UE_LOG(LogTemp, Warning, TEXT("Grab Ability reporting for duty!"));

}


// Called every frame
void UGrabAbility::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector playerViewPointLocation;
	FRotator playerViewPointRotation;

	// Get player view point this tick
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT	playerViewPointLocation,
		OUT	playerViewPointRotation
	);

	// Logs to console our players current position and rotation
	UE_LOG(LogTemp, Warning, TEXT("Location is: %s, Position is: %s"), 
		*playerViewPointLocation.ToString(), 
		*playerViewPointRotation.ToString()
	);


	// Ray-cast out to reach distance

	// See what we hit





}

