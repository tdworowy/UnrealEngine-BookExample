// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstPawn.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AFirstPawn::AFirstPawn() {
  // Set this pawn to call Tick() every frame.  You can turn this off to improve
  // performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
  MeshComponent =
      CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
  SetRootComponent(Cast<USceneComponent>(MeshComponent));

  CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
  CameraBoom->SetupAttachment(RootComponent);

  FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FallowCamera"));
  FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

  Speed = 500.f;
  Direction = FVector2D(0.f, 0.f);
}

// Called when the game starts or when spawned
void AFirstPawn::BeginPlay() { Super::BeginPlay(); }
void AFirstPawn::E_keyPressed() {
  UE_LOG(LogTemp, Warning, TEXT("E key pressed"));
}
void AFirstPawn::E_keyReleased() {
  UE_LOG(LogTemp, Warning, TEXT("E key released"));
}
void AFirstPawn::ShiftKey(float value) {
  if (value != 0.0f) {
    UE_LOG(LogTemp, Warning, TEXT("SHIFT key axis value: %f"), value);
  }
}
void AFirstPawn::MoveForward(float Value) {
  if (Value != 0.0f) {
    UE_LOG(LogTemp, Warning, TEXT("MoveForward: %f"), Value);
  }
  Direction.X = Value;
}
void AFirstPawn::MoveRight(float Value) {
  if (Value != 0.0f) {
    UE_LOG(LogTemp, Warning, TEXT("MoveRight: %f"), Value);
  }
  Direction.Y = Value;
}
// Called every frame
void AFirstPawn::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);

  FVector Location = GetActorLocation();
  FVector DeltaLocation = FVector(Direction.X, Direction.Y, 0.f);
  DeltaLocation.Normalize();
  DeltaLocation *= Speed * DeltaTime;
  Location += DeltaLocation;
  SetActorLocation(Location);
}

// Called to bind functionality to input
void AFirstPawn::SetupPlayerInputComponent(
    UInputComponent *PlayerInputComponent) {
  Super::SetupPlayerInputComponent(PlayerInputComponent);
  check(PlayerInputComponent);
  PlayerInputComponent->BindAction("E_Key", IE_Pressed, this,
                                   &AFirstPawn::E_keyPressed);
  PlayerInputComponent->BindAction("E_Key", IE_Released, this,
                                   &AFirstPawn::E_keyReleased);

  PlayerInputComponent->BindAxis("SHIFT_Key", this, &AFirstPawn::ShiftKey);
  PlayerInputComponent->BindAxis("MoveForward", this, &AFirstPawn::MoveForward);
  PlayerInputComponent->BindAxis("MoveRight", this, &AFirstPawn::MoveRight);
}
