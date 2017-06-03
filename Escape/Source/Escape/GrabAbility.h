// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "GrabAbility.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UGrabAbility : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabAbility();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	float reach = 200.0f;  // how far we want the line trace to extend out to
	
	// This corresponds to the physics handle component we added on our default pawn Blueprint (ourself)
	// We set it to nullptr because its best when declaring a pointer to set it to null.  
	// Special fact# "nullptr" actually points to the memory address of 0.
	UPhysicsHandleComponent* physicsHandle = nullptr; 

	UInputComponent* inputComponent = nullptr;

};
