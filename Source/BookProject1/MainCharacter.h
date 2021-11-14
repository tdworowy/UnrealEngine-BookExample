// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

DECLARE_DELEGATE(FRotateDelegate);
DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(float, FDynamicRotateDelegate, float, RotationSpeed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDynamicMulticastRotateDelegate, bool, bPlaySound); // can find "Bind Event to Dynamic Multicast Rotate Delegate" in BP in UE5


UCLASS()
class BOOKPROJECT1_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;


public:
	// Sets default values for this character's properties
	AMainCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerStats")
		float Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerStats")
		float MaxHealth;

	FORCEINLINE float GetHealth() { return Health; }
	void SetHealth(float Amount); //{ Amount > MaxHealth ? Health = MaxHealth : Health = Amount; }
	FORCEINLINE void SetMaxHealth(float Amount) { MaxHealth = Amount; }
	FRotateDelegate RotateDelegate;
	FDynamicRotateDelegate DynamicRotateDelegate;
	
	void ESCDown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveForward(float Value);
	void MoveRight(float Value);
	void LMBDown();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Anims")
		class UAnimMontage* AttackMontage;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
		bool bAttacking;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Controller")
		class AMainPlayerController* MainPlayerController;
	
	UFUNCTION(BlueprintCallable)
		void SetRotatingActorRates(float Rate);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void SaveGame();

	UFUNCTION(BlueprintCallable)
		void LoadGame();
	
	UFUNCTION(BlueprintCallable)
		void ToggleAllRotators();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float RotationgActorRate;

};

