// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FirstPawn.generated.h"
#include "GameFramework/Pawn.h"

UCLASS()
class BOOKPROJECT1_API AFirstPawn : public APawn {
  GENERATED_BODY()
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera,
            meta = (AllowPrivateAccess = "true"))
  class UStaticMeshComponent *MeshComponent;

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera,
            meta = (AllowPrivateAccess = "true"))
  class USpringArmComponent *CameraBoom;

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera,
            meta = (AllowPrivateAccess = "true"))
  class UCameraComponent *FollowCamera;

public:
  // Sets default values for this pawn's properties
  AFirstPawn();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;
  void E_keyPressed();
  void E_keyReleased();
  void ShiftKey(float value);
  void MoveForward(float value);
  void MoveRight(float value);
  UPROPERTY(EditDefaultsOnly, BluePrintReadWrite, Category = "Movement")
  float Speed;
  UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = "Movement")
  FVector2D Direction;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  // Called to bind functionality to input
  virtual void SetupPlayerInputComponent(
      class UInputComponent *PlayerInputComponent) override;
};
