// This is the main DLL file.

#include <iostream>

#include "AstriumBridgeLib.h"

using namespace System::Collections::Generic;

namespace AstriumBridgeLib
{
	int AstriumChopper::Initialise(char* ip)
	{
		int errCode = 0;

		if (chopper == nullptr) {
			chopper = gcnew AstriumComms::Chopper(gcnew System::String(ip));
		}

		return errCode;
	}

	int AstriumChopper::GetStatus(unsigned int channel, char* result, int size)
	{
		if (chopper == nullptr)
		{
			return -1;
		}
		
		System::String^ status = chopper->GetStatus(channel);

		StringToCharArray(status, result, size);

		return 0;
	}

	void AstriumChopper::StringToCharArray(String^ str, char* result, int size)
	{
		using namespace Runtime::InteropServices;
		IntPtr p = Marshal::StringToHGlobalAnsi(str);
		strncpy_s(result, size, static_cast<char*>(p.ToPointer()), size-1);
		Marshal::FreeHGlobal(p);
	}
}

__declspec(dllexport) int Initialise(char* ip)
{
    return AstriumBridgeLib::AstriumChopper::Initialise(ip);       
}

__declspec(dllexport) int GetStatus(unsigned int channel, char* result, int size)
{
	return AstriumBridgeLib::AstriumChopper::GetStatus(channel, result, size);
}