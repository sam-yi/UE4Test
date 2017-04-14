// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();
	void OpenTheDoor();
	void CloseTheDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	
	UPROPERTY(EditAnywhere)
	ATriggerVolume* pressurePlate;

	UPROPERTY(EditAnywhere)
	float doorCloseDelay = 1.0f;

	UPROPERTY(EditAnywhere)
	FRotator doorRotation; // Rotation set in the editor

	// time by which the door was last opened
	float lastDoorOpenTime;
	// reference to our player Actor which is just the defaultPawn
	AActor* actorThatOpens;
	// initial closed rotation of the Door
	FRotator initialRotation;
	// the Owning door Actor
	AActor* Owner;
};
