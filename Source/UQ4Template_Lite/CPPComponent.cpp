// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPComponent.h"
#include "Kismet/KismetSystemLibrary.h"
// Sets default values
ACPPComponent::ACPPComponent()
{
	GoalLocation = FVector3f(5.f, 5.f, 5.f);

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SceneComponentを作成
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	//SceneComponentをRootComponentに設定する
	RootComponent = DefaultSceneRoot;

	//StaticMeshを作成
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	TObjectPtr<UStaticMesh> mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/BasicShapes/Plane.Plane"), NULL, LOAD_None, NULL);
	StaticMeshComponent->SetStaticMesh(mesh);

	StaticMeshComponent->SetRelativeScale3D(FVector(GoalLocation));
	//Materialを作成
	TObjectPtr<UMaterial> material = LoadObject<UMaterial>(NULL, TEXT("/Engine/EngineDebugMaterials/BoneWeightMaterial.BoneWeightMaterial"), NULL, LOAD_None, NULL);
	StaticMeshComponent->SetMaterial(0,material);

	//StaticMeshComponentをRootComponentにAttachする
	StaticMeshComponent->SetupAttachment(RootComponent);


	//ArrowComponentの位置を設定する
	//Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));

	////ArrowComponentの位置を設定する
	//Arrow->SetRelativeLocation(FVector(50.f, 0, 0));//FVector(5720, 260, 40));

	////ArrowComponentをStaticMeshCompoentにAttachする
	//Arrow->SetupAttachment(StaticMeshComponent);
}

// Called when the game starts or when spawned
void ACPPComponent::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACPPComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

