#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpActor.generated.h"

class UStaticMeshComponent;
class USphereComponent;

UCLASS()
class PRC_API APickUpActor : public AActor
{
    GENERATED_BODY()
public:
    APickUpActor();

    UFUNCTION(BlueprintCallable, Category = "Pickup")
    void Collect(AActor* Collector);
protected:
    UPROPERTY(VisibleAnywhere, Category = "Components")
    TObjectPtr<USphereComponent> CollisionSphere;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    TObjectPtr<UStaticMeshComponent> Mesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
    float PointValue = 10.f;
};
