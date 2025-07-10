// MyCharacter.cpp
#include "MyCharacter.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AMyCharacter::AMyCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMyCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Movement
    PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

    // Look (Mouse)
    PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::Turn);         // Yaw
    PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::LookUp);     // Pitch

    // Jumping
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::StartJump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJump);
}

// Movement
void AMyCharacter::MoveForward(float Value)
{
    AddMovementInput(GetActorForwardVector() * Value);
}

void AMyCharacter::MoveRight(float Value)
{
    AddMovementInput(GetActorRightVector() * Value);
}

// Mouse Look
void AMyCharacter::Turn(float Value)
{
    AddControllerYawInput(Value);
}

void AMyCharacter::LookUp(float Value)
{
    AddControllerPitchInput(Value);
}

// Jump
void AMyCharacter::StartJump()
{
    bPressedJump = true;
}

void AMyCharacter::StopJump()
{
    bPressedJump = false;
}