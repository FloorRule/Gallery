

#include <iostream>
#include <windows.h>
#include <psapi.h>

using namespace std;

void printProcessNameAndID(DWORD processID)
{

	TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

	// Get a handle to the process.
	// Note that OpenProcess return handler to the process by it's ID (the variable processID)
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID);

	// Get the process name (you don't need to understand fully the following part of code) 
	/*
		Note that both EnumProcessModules and GetModuleBaseName require by their MSDN page
		to include the header file <psapi.h>
	*/
	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;

		
		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod),
			&cbNeeded))
		{
			GetModuleBaseName(hProcess, hMod, szProcessName,
				sizeof(szProcessName) / sizeof(TCHAR));
		}
	}

	// Print the process name and identifier.
	// NOT IMPORTANT: wcout is used because szProcessName is in unicode (w=wide)
	wcout << szProcessName << " (PID: " << processID << ")" << endl;

	// Release the handle to the process.

	CloseHandle(hProcess);
}

int main(void)
{
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;

	/*
	Note that both EnumProcesses requires by its MSDN page
	to include the header file <psapi.h>
	*/

	// Get the list of process identifiers.

	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		cout << "Error getting the process list (" << GetLastError() << ")" << endl;
		return 1;
	}

	// Calculate how many process identifiers were returned.

	cProcesses = cbNeeded / sizeof(DWORD);

	// Print the name and process identifier for each process.

	for (i = 0; i < cProcesses; i++)
	{
		if (aProcesses[i] != 0)
		{
			printProcessNameAndID(aProcesses[i]);
		}
	}

	getchar();
	return 0;
}


