// AstriumBridgeLib.h

#pragma once

#include <boost/bind.hpp>
#include <boost/function.hpp>

#include "ChopperWrapper.h"

namespace AstriumBridgeLib {
	public ref class AstriumChopper
	{
	private:
		static Wrapper::IChopper^ chopper;
		
		static void StringToCharArray(System::String^ str, char* result, int size);
		static int sendCommand(boost::function0<System::String^> func, char* result, int size);

	public:
		static int Initialise(const char* ip, bool mock);
		static int Calibrate(char* result, int size);
		static int GetStatus(unsigned int channel, char* result, int size);
		static int SetFreq(unsigned int channel, int speed, char* result, int size);
		static int SetPhase(unsigned int channel, double phase, char* result, int size);
		static int Brake(unsigned int channel, char* result, int size);
		static int Resume(unsigned int channel, char* result, int size);
	};
}
