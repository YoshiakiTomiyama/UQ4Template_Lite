// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPComponent.generated.h"
//#include "AI/NavigationSystemBase.h"
//#include "Components/BoxComponent.h"
UCLASS()
class UQ4TEMPLATE_LITE_API ACPPComponent : public AActor
{
	GENERATED_BODY()
private:

public:
	// Sets default values for this actor's properties
	ACPPComponent();

	UPROPERTY(EditAnywhere)
		TObjectPtr<USceneComponent> DefaultSceneRoot; // EditAnywhere レベルエディターおよびブループリントエディター上での閲覧・編集が可能

	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent>StaticMeshComponent;

	UPROPERTY(EditAnywhere)
		FVector3f GoalLocation;

	UPROPERTY(EditAnywhere)
		TObjectPtr<UUserWidget>Widget;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
