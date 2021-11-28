// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class BOOKPROJECT1_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();
	UPROPERTY(EditAnywhere, Category = "Pawn")
		class UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere, Category = "BehaviorTree", Meta = (MakeEditWidget = true))
		FVector PatrolPoint1;

	UPROPERTY(EditAnywhere, Category = "BehaviorTree", Meta = (MakeEditWidget = true))
		FVector PatrolPoint2;

	UPROPERTY(EditAnywhere, Category = "BehaviorTree", Meta = (MakeEditWidget = true))
		FVector PatrolPoint3;

	UPROPERTY(EditAnywhere, Category = "BehaviorTree", Meta = (MakeEditWidget = true))
		FVector PatrolPoint4;

	class AEnemyController* EnemyController;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
