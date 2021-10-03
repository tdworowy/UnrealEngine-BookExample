// Copyright Epic Games, Inc. All Rights Reserved.

#include "BookProject1GameMode.h"
#include "BookProject1Character.h"
#include "UObject/ConstructorHelpers.h"

ABookProject1GameMode::ABookProject1GameMode()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("Class'/Script/BookProject1.FirstPawn'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	
	} */
}

