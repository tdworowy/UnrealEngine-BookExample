// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class BOOKPROJECT1_API AHealthPickup : public AItem
{
	GENERATED_BODY()

public:	
	AHealthPickup();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
	float HealingAmount;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult) override;
		
};
