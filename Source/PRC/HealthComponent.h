// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDeath);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRC_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Stats")
	float MaxHealth = 100.f;
	float CurrentHealth = 0.f;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerDeath OnPlayerDeath;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(float Amount);
	UFUNCTION(BlueprintCallable)
	void Heal(float Amount);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
