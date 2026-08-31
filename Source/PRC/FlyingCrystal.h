// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlyingCrystal.generated.h"

UCLASS()
class PRC_API AFlyingCrystal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlyingCrystal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "Crystal")
	TObjectPtr<UStaticMeshComponent> CrystalMesh;

	UPROPERTY(EditAnywhere, Category = "Crystal|Float")
	float FloatSpeed = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Crystal|Float")
	float FloatHeight = 25.0f;

	UPROPERTY(EditAnywhere, Category = "Crystal|Float")
	float RotationSpeed = 45.0f;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	void Collect(class AHeroCharacter* Collector);

private:
	float RunningTime = 0.0f;
	FVector StartLocation;

};
