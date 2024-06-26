// Fill out your copyright notice in the Description page of Project Settings.

#include "MainAnimInstance.h"
#include "Enemy.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "Kismet/KismetMathLibrary.h"
#include "MainCharacter.h"

void UMainAnimInstance::NativeInitializeAnimation() {
  Super::NativeInitializeAnimation();
  if (Pawn == nullptr) {
    Pawn = TryGetPawnOwner();
    if (Pawn) {
      Main = Cast<AMainCharacter>(Pawn);
      Enemy = Cast<AEnemy>(Pawn);
    }
  }
}

void UMainAnimInstance::UpdateAnimationProperties(float DeltaTime) {

  if (Pawn == nullptr) {
    Pawn = TryGetPawnOwner();
  }
  if (Pawn) {
    FVector Speed = Pawn->GetVelocity();
    FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);
    MovementSpeed = LateralSpeed.Size();

    bIsInAir = Pawn->GetMovementComponent()->IsFalling();

    FRotator Rotation = Pawn->GetActorRotation();
    FRotator Delta =
        UKismetMathLibrary::NormalizedDeltaRotator(RotationLastFrame, Rotation);
    float Target = Delta.Yaw / DeltaTime;
    float Interp = FMath::FInterpTo(YawDelta, Target, DeltaTime, 6.0f);
    YawDelta = FMath::Clamp(Interp, -90.f, 90.f);
    RotationLastFrame = Rotation;

    if (Main == nullptr) {
      Main = Cast<AMainCharacter>(Pawn);
    }
    if (Main) {
      int Acceleration =
          Main->GetCharacterMovement()->GetCurrentAcceleration().Size();
      if (Acceleration > 0) {
        bIsAccelerating = true;
      } else {
        bIsAccelerating = false;
      }
    }
    if (Enemy) {
      bIsAccelerating = Enemy->bIsAccelerating;
    } else {
      Enemy = Cast<AEnemy>(Pawn);
      if (Enemy) {
        bIsAccelerating = Enemy->bIsAccelerating;
      }
    }
  }
}
