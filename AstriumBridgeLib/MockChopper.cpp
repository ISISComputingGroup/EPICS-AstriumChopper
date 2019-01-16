// This is a wrapper to allow mocking the chopper comms.

#include "ChopperWrapper.h"

namespace Wrapper
{
	MockChopper::MockChopper(std::string controllerID) {
		this->acceptString = gcnew System::String(std::string("#" + controllerID + "#ACCEPT ").c_str());
	}

	System::String^ MockChopper::GetStatus(unsigned int channel) {
		return acceptString + gcnew System::String("CH=0# State= INACTIVE#ASPEED= 0#RSPEED= 0#APHASE= 0#RPHASE= 0#AVETO = 0#DIR   = CCW#MONIT = er#FLOWR = 3,81325301204819#WTEMP = 17#MTEMP = 22#MVIBR = 0#MVACU = 0,000546822026457275#DATE  = 15.01.2019#TIME");
	}

	System::String^ MockChopper::Calibrate() {
		return acceptString;
	}

	System::String^ MockChopper::SetGear(unsigned int channel, int speed) {
		return acceptString;
	}
	
	System::String^ MockChopper::SetPhase(unsigned int channel, double phase) {
		return acceptString;
	}

	System::String^ MockChopper::SetBrake(unsigned int channel) {
		return acceptString;
	}

	System::String^ MockChopper::SetResume(unsigned int channel) {
		return acceptString;
	}
}
