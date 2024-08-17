#include <Windows.h>
#include <iostream>
#include "RunAImbot.h"

DWORD WINAPI HackThread(HMODULE hModule)
{
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	do
	{
		RunAimbot();
		Sleep(1);
	} while (!GetAsyncKeyState(VK_INSERT));

	FreeLibraryAndExitThread(hModule, 0);
	FreeConsole();
	fclose(f);

	return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID resrs)
{
	if (reason == 1)
	{
		DisableThreadLibraryCalls(hModule);

		HANDLE thread;
		thread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)(HackThread), NULL, NULL, NULL);

		if (thread)
			CloseHandle(thread);
	}
	return TRUE;
}