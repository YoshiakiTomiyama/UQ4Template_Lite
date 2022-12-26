// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPComponent.h"
#include "Kismet/KismetSystemLibrary.h"
// Sets default values
ACPPComponent::ACPPComponent()
{
	GoalLocation = FVector3f(5.f, 5.f, 5.f);

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SceneComponent‚ğì¬
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	//SceneComponent‚ğRootComponent‚Éİ’è‚·‚é
	RootComponent = DefaultSceneRoot;

	//StaticMesh‚ğì¬
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	TObjectPtr<UStaticMesh> mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/BasicShapes/Plane.Plane"), NULL, LOAD_None, NULL);
	StaticMeshComponent->SetStaticMesh(mesh);

	StaticMeshComponent->SetRelativeScale3D(FVector(GoalLocation));
	//Material‚ğì¬
	TObjectPtr<UMaterial> material = LoadObject<UMaterial>(NULL, TEXT("/Engine/EngineDebugMaterials/BoneWeightMaterial.BoneWeightMaterial"), NULL, LOAD_None, NULL);
	StaticMeshComponent->SetMaterial(0,material);

	//StaticMeshComponent‚ğRootComponent‚ÉAttach‚·‚é
	StaticMeshComponent->SetupAttachment(RootComponent);


	//ArrowComponent‚ÌˆÊ’u‚ğİ’è‚·‚é
	//Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));

	////ArrowComponent‚ÌˆÊ’u‚ğİ’è‚·‚é
	//Arrow->SetRelativeLocation(FVector(50.f, 0, 0));//FVector(5720, 260, 40));

	////ArrowComponent‚ğStaticMeshCompoent‚ÉAttach‚·‚é
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

