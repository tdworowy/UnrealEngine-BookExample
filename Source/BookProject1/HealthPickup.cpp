// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthPickup.h"
#include "MainCharacter.h"

AHealthPickup::AHealthPickup() { HealingAmount = 20.f; };
void AHealthPickup::OnOverlapBegin(UPrimitiveComponent *OverlappedComponent,
                                   AActor *OtherActor,
                                   UPrimitiveComponent *OtherComp,
                                   int32 OtherBodyIndex, bool bFromSweep,
                                   const FHitResult &SweepResult) {
  UE_LOG(LogTemp, Warning, TEXT("AHealthPIckup::OnOverlapBegin"));
  AMainCharacter *MainCharacter = Cast<AMainCharacter>(OtherActor);
  if (MainCharacter) {
    MainCharacter->SetHealth(MainCharacter->GetHealth() + HealingAmount);
  }
  Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp,
                        OtherBodyIndex, bFromSweep, SweepResult);
};
