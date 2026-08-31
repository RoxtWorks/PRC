// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCollectibleCountChanged, int32, NewCount);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRC_API UStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatComponent();

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Stats")
	float MoveSpeedMultiplier = 1.f;

	UPROPERTY(BlueprintReadOnly)
	int32 CollectibleCount = 0;

	UPROPERTY(BlueprintAssignable)
	FOnCollectibleCountChanged OnCollectibleCountChanged;

	float GetMoveSpeed(float BaseSpeed) const;
	void AddCollectible(int32 Amount = 1);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
