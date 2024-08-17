#include "RunAImbot.h"
#include <Windows.h>
#include <iostream>
#include "Vector3.h"
#include "engine.h"
#include "AimAt.h"

void RunAimbot()
{
	const auto moduleBase = reinterpret_cast<std::uintptr_t>(GetModuleHandle("ac_client.exe"));

	if (moduleBase == 0)
	{
		std::cout << "[=] : moduleBase :: 0" << std::endl;
		while (moduleBase == 0)
			continue;
	}

	const auto localPlayer= *reinterpret_cast<std::uintptr_t*>(moduleBase + 0x10F4F4);

	if (localPlayer == 0)
	{
		std::cout << "[=] : localPlayer :: 0" << std::endl;
		while (localPlayer == 0)
			continue;
	}

	const auto EntityList = reinterpret_cast<std::uintptr_t*>(moduleBase + 0x10F4F8);

	if (EntityList == 0)
	{
		std::cout << "[=] : EntityList :: 0" << std::endl;
		while (EntityList == 0)
			continue;
	}

	const auto numOfPlayers = *reinterpret_cast<std::int32_t*>(moduleBase + 0x10F500);

	if (numOfPlayers == 0)
	{
		std::cout << "[=] : EntityList :: 0" << std::endl;
		while (numOfPlayers == 0)
			continue;
	}

	


	for (int i = 0; i < numOfPlayers; ++i)
	{
		float threshold = 100.0f;

		const auto currentPlayer = reinterpret_cast<std::uintptr_t*>(EntityList + i * 0x4);

		auto Pitch = *reinterpret_cast<float*>(localPlayer + 0x44);
		auto Yaw = *reinterpret_cast<float*>(localPlayer + 0x40);
		

		float Distance = GetDistance(localPlayer, currentPlayer);

		if (Distance < threshold)
		{
			AimAt(currentPlayer, localPlayer);
		}
		else
		{
			if (Distance > threshold)
			{
				std::cout << "[=] : Failed to found A Close Player.." << std::endl;
				while (Distance > threshold)
					continue;
			}
		}
	}
}