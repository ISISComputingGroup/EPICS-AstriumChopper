// This is the main DLL file.

#include <iostream>
#include <string>
#include "AstriumBridgeLib.h"

using namespace System::Collections::Generic;

namespace AstriumBridgeLib
{
	int AstriumChopper::Initialise(const char* ip, bool mock)
	{
		if (chopper == nullptr) {
			if (mock) {
				chopper = gcnew Wrapper::MockChopper("NCS016");
			} else {
				chopper = gcnew Wrapper::AstriumChopper(gcnew System::String(ip));
			}
		}

		return 0;
	}

	int AstriumChopper::sendCommand(boost::function0<System::String^> func, char* result, int size) {
		/**
		Sends a command to the chopper, checking that it exists and places the resulting string in the specified result reference.
		**/
		if (chopper == nullptr) {
			return -1;
		}
		System::String^ status = func();
		StringToCharArray(status, result, size);

		return 0;
	}

	int AstriumChopper::GetStatus(unsigned int channel, char* result, int size)
	{
		return sendCommand(boost::bind<System::String^>(Wrapper::GetStatusProxy, gcroot<Wrapper::IChopper^>(chopper), channel), result, size);
	}

	int AstriumChopper::SetFreq(unsigned int channel, int speed, char* result, int size)
	{
		return sendCommand(boost::bind<System::String^>(Wrapper::SetGearProxy, gcroot<Wrapper::IChopper^>(chopper), channel, speed), result, size);
	}

	int AstriumChopper::SetPhase(unsigned int channel, double phase, char* result, int size)
	{
		return sendCommand(boost::bind<System::String^>(Wrapper::SetPhaseProxy, gcroot<Wrapper::IChopper^>(chopper), channel, phase), result, size);
	}

	int AstriumChopper::Brake(unsigned int channel, char* result, int size)
	{
		return sendCommand(boost::bind<System::String^>(Wrapper::SetBrakeProxy, gcroot<Wrapper::IChopper^>(chopper), channel), result, size);
	}

	int AstriumChopper::Calibrate(char* result, int size)
	{
		return sendCommand(boost::bind<System::String^>(Wrapper::CalibrateProxy, gcroot<Wrapper::IChopper^>(chopper)), result, size);
	}

	void AstriumChopper::StringToCharArray(System::String^ str, char* result, int size)
	{
		using namespace System::Runtime::InteropServices;
		System::IntPtr p = Marshal::StringToHGlobalAnsi(str);
		strncpy_s(result, size, static_cast<char*>(p.ToPointer()), size-1);
		Marshal::FreeHGlobal(p);
	}
}

__declspec(dllexport) int Initialise(const char* ip, bool mock)
{
    return AstriumBridgeLib::AstriumChopper::Initialise(ip, mock);       
}

__declspec(dllexport) int GetStatus(unsigned int channel, char* result, int size)
{
	return AstriumBridgeLib::AstriumChopper::GetStatus(channel, result, size);
}

__declspec(dllexport) int SetFreq(unsigned int channel, int speed, char* result, int size)
{
	return AstriumBridgeLib::AstriumChopper::SetFreq(channel, speed, result, size);
}

__declspec(dllexport) int SetPhase(unsigned int channel, double phase, char* result, int size)
{
	return AstriumBridgeLib::AstriumChopper::SetPhase(channel, phase, result, size);
}

__declspec(dllexport) int Brake(unsigned int channel, char* result, int size)
{
	return AstriumBridgeLib::AstriumChopper::Brake(channel, result, size);
}

__declspec(dllexport) int Calibrate(char* result, int size)
{
	return AstriumBridgeLib::AstriumChopper::Calibrate(result, size);
}

