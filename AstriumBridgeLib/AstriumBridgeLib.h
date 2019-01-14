// AstriumBridgeLib.h

#pragma once

using namespace System;

namespace AstriumBridgeLib {

	public ref class AstriumChopper
	{
	private:
		static AstriumComms::Chopper^ chopper;
		static void StringToCharArray(String^ str, char* result, int size);

	public:
		static int Initialise(char* ip);
		static int GetStatus(unsigned int channel, char* result, int size);
	};
}
