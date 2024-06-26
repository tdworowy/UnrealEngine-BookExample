// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseCharacter.h"
#include "CoreMinimal.h"
#include "Enemy.generated.h"

UCLASS()
class BOOKPROJECT1_API AEnemy : public ABaseCharacter {
  GENERATED_BODY()

public:
  // Sets default values for this character's properties
  AEnemy();
  UPROPERTY(EditAnywhere, Category = "Pawn")
  class UBehaviorTree *BehaviorTree;

  UPROPERTY(EditAnywhere, Category = "BehaviorTree",
            Meta = (MakeEditWidget = true))
  FVector PatrolPoint1;

  UPROPERTY(EditAnywhere, Category = "BehaviorTree",
            Meta = (MakeEditWidget = true))
  FVector PatrolPoint2;

  UPROPERTY(EditAnywhere, Category = "BehaviorTree",
            Meta = (MakeEditWidget = true))
  FVector PatrolPoint3;

  UPROPERTY(EditAnywhere, Category = "BehaviorTree",
            Meta = (MakeEditWidget = true))
  FVector PatrolPoint4;

  class AEnemyController *EnemyController;

  UPROPERTY(BlueprintReadOnly)
  bool bIsAccelerating;

  UFUNCTION(BlueprintCallable)
  void SetIsAccelerating(bool bAccelerating);

  UPROPERTY(VisibleAnywhere, Category = "BehaviorTree")
  class USphereComponent *AgroSphere;

  UPROPERTY(VisibleAnywhere, Category = "BehaviorTree")
  class USphereComponent *AttackSphere;

  UFUNCTION()
  void AgroSphereBeginOverlap(UPrimitiveComponent *OverlappedComponent,
                              AActor *OtherActor,
                              UPrimitiveComponent *OtherComp,
                              int32 OtherBodyIndex, bool bFromSweep,
                              const FHitResult &SweepResult);

  UFUNCTION()
  void AgroSphereEndOverlap(UPrimitiveComponent *OverlappedComponent,
                            AActor *OtherActor, UPrimitiveComponent *OtherComp,
                            int32 OtherBodyIndex);

  UFUNCTION()
  void AttackSphereBeginOverlap(UPrimitiveComponent *OverlappedComponent,
                                AActor *OtherActor,
                                UPrimitiveComponent *OtherComp,
                                int32 OtherBodyIndex, bool bFromSweep,
                                const FHitResult &SweepResult);

  UFUNCTION()
  void AttackSphereEndOverlap(UPrimitiveComponent *OverlappedComponent,
                              AActor *OtherActor,
                              UPrimitiveComponent *OtherComp,
                              int32 OtherBodyIndex);

  bool bAttackTimerStarted;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
  bool bInAttackRange;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
  float AttackMinTime;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
  float AttackMaxTime;

  FTimerHandle AttackTimer;

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  // Called to bind functionality to input
  virtual void SetupPlayerInputComponent(
      class UInputComponent *PlayerInputComponent) override;
};
