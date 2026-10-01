#include "PickUpActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

APickUpActor::APickUpActor()
{
    PrimaryActorTick.bCanEverTick = false;

    CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
    SetRootComponent(CollisionSphere);
    CollisionSphere->SetSphereRadius(80.f);
    CollisionSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    Mesh->SetupAttachment(CollisionSphere);
}

void APickUpActor::Collect(AActor* Collector)
{
    Destroy();
}
