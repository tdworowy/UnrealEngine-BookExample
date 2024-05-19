// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "EnemyController.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Kismet/GameplayStatics.h"
#include "MainCharacter.h"
#include "TimerManager.h"

// Sets default values
AEnemy::AEnemy() {
  // Set this character to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  AgroSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AgroSphere"));
  AgroSphere->SetupAttachment(GetRootComponent());

  AttackSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AttackSphere"));
  AttackSphere->SetupAttachment(GetRootComponent());

  AttackMinTime = .5f;
  AttackMaxTime = 1.5f;

  // bAttacking = false;
  bAttackTimerStarted = false;
  bInAttackRange = false;

  //	Health = 20.f;
  //	MaxHealth = 20.f;
  //	XP = 10;
  //	Damage = 20.f;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay() {
  Super::BeginPlay();
  FVector Location = GetActorLocation();
  EnemyController = Cast<AEnemyController>(GetController());
  EnemyController->GetBlackboard()->SetValueAsVector(TEXT("PatrolPoint1"),
                                                     PatrolPoint1 + Location);
  EnemyController->GetBlackboard()->SetValueAsVector(TEXT("PatrolPoint2"),
                                                     PatrolPoint2 + Location);
  EnemyController->GetBlackboard()->SetValueAsVector(TEXT("PatrolPoint3"),
                                                     PatrolPoint3 + Location);
  EnemyController->GetBlackboard()->SetValueAsVector(TEXT("PatrolPoint4"),
                                                     PatrolPoint4 + Location);

  AgroSphere->OnComponentBeginOverlap.AddDynamic(
      this, &AEnemy::AgroSphereBeginOverlap);
  AgroSphere->OnComponentEndOverlap.AddDynamic(this,
                                               &AEnemy::AgroSphereEndOverlap);
  AttackSphere->OnComponentBeginOverlap.AddDynamic(
      this, &AEnemy::AttackSphereBeginOverlap);
  AttackSphere->OnComponentEndOverlap.AddDynamic(
      this, &AEnemy::AttackSphereEndOverlap);
}

// Called every frame
void AEnemy::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) {
  Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemy::SetIsAccelerating(bool bAccelerating) {
  bIsAccelerating = bAccelerating;
}

void AEnemy::AgroSphereBeginOverlap(UPrimitiveComponent *OverlappedComponent,
                                    AActor *OtherActor,
                                    UPrimitiveComponent *OtherComp,
                                    int32 OtherBodyIndex, bool bFromSweep,
                                    const FHitResult &SweepResult) {
  if (OtherActor) {
    AMainCharacter *Main = Cast<AMainCharacter>(OtherActor);
    if (Main) {
      UE_LOG(LogTemp, Warning, TEXT("Main valid"))
      if (EnemyController == nullptr) {
        EnemyController = Cast<AEnemyController>(GetController());
      }
      EnemyController->GetBlackboard()->SetValueAsObject(TEXT("TargetActor"),
                                                         Main);
    }
  }
}

void AEnemy::AgroSphereEndOverlap(UPrimitiveComponent *OverlappedComponent,
                                  AActor *OtherActor,
                                  UPrimitiveComponent *OtherComp,
                                  int32 OtherBodyIndex) {
  if (OtherActor) {
    AMainCharacter *Main = Cast<AMainCharacter>(OtherActor);
    if (Main) {
      if (EnemyController == nullptr) {
        EnemyController = Cast<AEnemyController>(GetController());
      }
      EnemyController->GetBlackboard()->SetValueAsObject(TEXT("TargetActor"),
                                                         nullptr);
    }
  }
}

void AEnemy::AttackSphereBeginOverlap(UPrimitiveComponent *OverlappedComponent,
                                      AActor *OtherActor,
                                      UPrimitiveComponent *OtherComp,
                                      int32 OtherBodyIndex, bool bFromSweep,
                                      const FHitResult &SweepResult) {
  if (OtherActor) {
    AMainCharacter *Main = Cast<AMainCharacter>(OtherActor);
    if (Main) {
      if (EnemyController == nullptr) {
        EnemyController = Cast<AEnemyController>(GetController());
      }
      EnemyController->GetBlackboard()->SetValueAsBool(TEXT("InAttackRange"),
                                                       true);
      bInAttackRange = true;
      bAttacking = true;
    }
  }
}

void AEnemy::AttackSphereEndOverlap(UPrimitiveComponent *OverlappedComponent,
                                    AActor *OtherActor,
                                    UPrimitiveComponent *OtherComp,
                                    int32 OtherBodyIndex) {
  if (OtherActor) {
    AMainCharacter *Main = Cast<AMainCharacter>(OtherActor);
    if (Main) {
      if (EnemyController == nullptr) {
        EnemyController = Cast<AEnemyController>(GetController());
      }
      EnemyController->GetBlackboard()->SetValueAsBool(TEXT("InAttackRange"),
                                                       false);
      bInAttackRange = false;
      bAttacking = false;
    }
  }
}
