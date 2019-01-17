// This is a wrapper to allow mocking the chopper comms.

#include "ChopperWrapper.h"

namespace Wrapper
{
	MockChopper::MockChopper(std::string controllerID) {
		this->phase = 0;
		this->speed = 0;
		this->acceptString = gcnew System::String(std::string("#" + controllerID + "#ACCEPT ").c_str());
		this->rejectString = gcnew System::String(std::string("#" + controllerID + "#NCCEPT ").c_str());
		this->state="E_STOP";
	}

	System::String^ MockChopper::GetStatus(unsigned int channel) {
		std::stringstream returnStream;
		const char* stateStr = (const char*) (System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(state)).ToPointer();
		returnStream.imbue(std::locale("German_germany"));
		returnStream << "CH=" << channel << "# State= " << stateStr;
		returnStream << "#ASPEED= " << speed << "#RSPEED= 0"; //Bug in device means RSPEED is never actually set
		returnStream << "#APHASE= " << phase << "#RPHASE= " << phase;
		returnStream << "#AVETO = 0#DIR   = CCW#MONIT = er#FLOWR = 3,813#WTEMP = 17#MTEMP = 22#MVIBR = 0#MVACU = 0,0005468#DATE  = 15.01.2019#TIME";
		
		const std::string returnStr = returnStream.str();
		return acceptString + gcnew System::String(returnStr.c_str());
	}

	System::String^ MockChopper::Calibrate() {
		// Actually device state goes E_STOP->INACTIVE->COMMUTATION->ASYNCHRON->POSITION but don't want to complicate mock
		state = "POSITION";
		return acceptString;
	}

	System::String^ MockChopper::SetGear(unsigned int channel, int speed) {
		if (speed < 0) {
			return rejectString + gcnew System::String("Invalid speed");
		} else {
			this->speed = speed * 10; //Device actually sends 10 times what is set
			state = "POSITION";
			return acceptString;
		}
	}
	
	System::String^ MockChopper::SetPhase(unsigned int channel, double phase) {
		this->phase = phase;
		return acceptString;
	}

	System::String^ MockChopper::SetBrake(unsigned int channel) {
		state = "BRAKE";
		speed = 0;
		return acceptString;
	}

	System::String^ MockChopper::SetResume(unsigned int channel) {
		return acceptString;
	}
}
