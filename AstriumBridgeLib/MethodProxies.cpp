// These proxies will allow us to use boost to bind to methods.

#include "ChopperWrapper.h"

namespace Wrapper
{
	System::String^ GetStatusProxy(gcroot<Wrapper::IChopper^> This, unsigned int channel) {
		return This->GetStatus(channel);
	}
	
	System::String^ SetGearProxy(gcroot<Wrapper::IChopper^> This, unsigned int channel, int speed) {
		return This->SetGear(channel, speed);
	}

	System::String^ SetPhaseProxy(gcroot<Wrapper::IChopper^> This, unsigned int channel, double phase) {
		return This->SetPhase(channel, phase);
	}

	System::String^ SetBrakeProxy(gcroot<Wrapper::IChopper^> This, unsigned int channel) {
		return This->SetBrake(channel);
	}

	System::String^ SetResumeProxy(gcroot<Wrapper::IChopper^> This, unsigned int channel) {
		return This->SetResume(channel);
	}

	System::String^ CalibrateProxy(gcroot<Wrapper::IChopper^> This) {
		return This->Calibrate();
	}
}
