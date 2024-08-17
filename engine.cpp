#include "engine.h"
#include <Windows.h>
#include <iostream>
#include "Vector3.h"

float GetDistance(uintptr_t localPlayer, uintptr_t* currentPlayer)
{


    float currentPlayerXAccess = *reinterpret_cast<float*>(currentPlayer + 0x4);
    float currentPlayerYAccess = *reinterpret_cast<float*>(currentPlayer + 0x8);
    float currentPlayerZAccess = *reinterpret_cast<float*>(currentPlayer + 0xC);

    float localPlayerXAccess = *reinterpret_cast<float*>(localPlayer + 0x4);
    float localPlayerYAccess = *reinterpret_cast<float*>(localPlayer + 0x8);
    float localPlayerZAccess = *reinterpret_cast<float*>(localPlayer + 0xC);

    Vector3 delta = Vector3(currentPlayerXAccess - localPlayerXAccess, currentPlayerYAccess - localPlayerYAccess, currentPlayerZAccess - localPlayerZAccess);

    float Distance = sqrt(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);

    return Distance;
}