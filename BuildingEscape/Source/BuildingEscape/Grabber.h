// Copyright Josh "Asheron909" Deal 2018

#pragma once

#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	// How far ahead of the player can we reach in cm
	float Reach = 180.0f;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	// Ray-cast and grab what's in reach
	void Grab();

	// Ray-cast and grab what's in reach
	void Release();

	// Find attached physics component
	void FindPhysicsHandleComponent();

	// Setup (assumed) attached Input Component
	void SetupInputComponent();

	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	// Returns current end of reach line
	FVector GetReachLineStart();

	// Returns current end of reach line
	FVector GetReachLineEnd();
};
