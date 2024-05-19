// Fill out your copyright notice in the Description page of Project Settings.

#include "OverLapActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AOverLapActor::AOverLapActor() {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
  SetRootComponent(PickupMesh);

  OverlapBox = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapBox"));
  OverlapBox->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AOverLapActor::BeginPlay() {
  Super::BeginPlay();
  OverlapBox->OnComponentBeginOverlap.AddDynamic(this,
                                                 &AOverLapActor::BeginOverlap);
  OverlapBox->OnComponentEndOverlap.AddDynamic(this,
                                               &AOverLapActor::EndOverlap);

  PickupMesh->OnComponentHit.AddDynamic(this, &AOverLapActor::ComponentHit);
}

// Called every frame
void AOverLapActor::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void AOverLapActor::BeginOverlap(UPrimitiveComponent *OverlappedComponent,
                                 AActor *OtherActor,
                                 UPrimitiveComponent *OtherComp,
                                 int32 OtherBodyIndex, bool bFromSweep,
                                 const FHitResult &SweepResult) {
  UE_LOG(LogTemp, Warning, TEXT("BeginOverlap"));
}

void AOverLapActor::EndOverlap(UPrimitiveComponent *OverlappedComponent,
                               AActor *OtherActor,
                               UPrimitiveComponent *OtherComp,
                               int32 OtherBodyIndex) {
  UE_LOG(LogTemp, Warning, TEXT("EndOverlap"));
}

void AOverLapActor::ComponentHit(UPrimitiveComponent *HitComponent,
                                 AActor *OtherActor,
                                 UPrimitiveComponent *OtherComp,
                                 FVector NormalImpulse, const FHitResult &Hit) {
  UE_LOG(LogTemp, Warning, TEXT("ComponentHit"));
}