#include "AimAt.h"
#include <Windows.h>
#include <iostream>


void AimAt(uintptr_t* currentPlayer, uintptr_t localPlayer)
{
    constexpr float PI = 3.14159265358979323846f;

    float* currentPlayerXAccess = reinterpret_cast<float*>(currentPlayer + 0x4);
    float* currentPlayerYAccess = reinterpret_cast<float*>(currentPlayer + 0x8);
    float* currentPlayerZAccess = reinterpret_cast<float*>(currentPlayer + 0xC);

    float* localPlayerXAccess = reinterpret_cast<float*>(localPlayer + 0x4);
    float* localPlayerYAccess = reinterpret_cast<float*>(localPlayer + 0x8);
    float* localPlayerZAccess = reinterpret_cast<float*>(localPlayer + 0xC);

    float* localPlayerYaw = reinterpret_cast<float*>(localPlayer + 0x40);
    float* localPlayerPitch = reinterpret_cast<float*>(localPlayer + 0x44);

    float deltaX = *currentPlayerXAccess - *localPlayerXAccess;
    float deltaY = *currentPlayerYAccess - *localPlayerYAccess;
    float deltaZ = *currentPlayerZAccess - *localPlayerZAccess;

    float XYHypotenuse = sqrt((deltaX * deltaX) + (deltaY * deltaY));

    float viewAnglesYawDegrees = atan2(deltaY, deltaX) * (180 / PI);

    float viewAnglesPitchDegrees = atan2(deltaZ, XYHypotenuse) * (180 / PI);

    *localPlayerYaw = viewAnglesYawDegrees;
    *localPlayerPitch = viewAnglesPitchDegrees;
}