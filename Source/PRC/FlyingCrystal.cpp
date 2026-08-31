// Fill out your copyright notice in the Description page of Project Settings.

#include "FlyingCrystal.h"
#include "HeroCharacter.h"

// Sets default values
AFlyingCrystal::AFlyingCrystal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CrystalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CrystalMesh"));
	RootComponent = CrystalMesh;
	CrystalMesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

}

// Called when the game starts or when spawned
void AFlyingCrystal::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

    CrystalMesh->OnComponentBeginOverlap.AddDynamic(this, &AFlyingCrystal::OnOverlapBegin);

}

// Called every frame
void AFlyingCrystal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    RunningTime += DeltaTime;

    // Bob up and down around StartLocation using a sine wave.
    float ZOffset = FMath::Sin(RunningTime * FloatSpeed) * FloatHeight;
    FVector NewLocation = StartLocation;
    NewLocation.Z += ZOffset;
    SetActorLocation(NewLocation);

    // Constant yaw spin — framerate independent via DeltaTime.
    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw += RotationSpeed * DeltaTime;
    SetActorRotation(NewRotation);

}

void AFlyingCrystal::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    UE_LOG(LogTemp, Warning, TEXT("Overlap fired: %s"), *OtherActor->GetName());
    if (AHeroCharacter* Hero = Cast<AHeroCharacter>(OtherActor))
    {
        Collect(Hero);
    }
}

void AFlyingCrystal::Collect(AHeroCharacter* Collector)
{
    Collector->AddCollectible();
    UE_LOG(LogTemp, Warning, TEXT("Crystal collected!"));
    Destroy();
}


