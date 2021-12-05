// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class BOOKPROJECT1_API UMainAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	
	UFUNCTION(BlueprintCallable, Category = AnimationProperties)
		void UpdateAnimationProperties(float DeltaTime);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		float MovementSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
		bool bIsInAir;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movemnet)
		bool bIsAccelerating;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movemnet)
		float YawDelta;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movemnet)
		FRotator RotationLastFrame;
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movemnet)
		class APawn* Pawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movemnet)
		class AMainCharacter* Main;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		class AEnemy* Enemy;

};