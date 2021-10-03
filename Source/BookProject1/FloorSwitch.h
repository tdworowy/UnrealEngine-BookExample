// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorSwitch.generated.h"

UCLASS()
class BOOKPROJECT1_API AFloorSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorSwitch();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FloorSwitch")
	class UBoxComponent* TriggerBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FloorSwitch")
	class UStaticMeshComponent* FloorSwitch;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FloorSwitch")
	class UStaticMeshComponent* Door;

	UPROPERTY(BlueprintReadWrite, Category = "FloorSwitch")
	FVector InitialDoorLocation;

	UPROPERTY(BlueprintReadWrite, Category = "FloorSwitch")
	FVector InitialSwitchLocation;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);
	
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);


	UFUNCTION(BlueprintImplementableEvent,Category = "FloorSwitch")
	void ActivateFloorSwitch();
	
	UFUNCTION(BlueprintImplementableEvent,Category = "FloorSwitch")
	void DeactivateFloorSwitch();

	UFUNCTION(BlueprintCallable, Category = "FloorSwitch")
	void UpdateFloorSwitchLocation(float DoorLocation, float SwitchLocation);
};

