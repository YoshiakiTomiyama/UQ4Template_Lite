// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPHelloWorld.generated.h"

UCLASS()
class UQ4TEMPLATE_LITE_API ACPPHelloWorld : public AActor
{
	GENERATED_BODY()

private:
	FString string = "C++ Hello";
public:	
	// Sets default values for this actor's properties
	ACPPHelloWorld();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
