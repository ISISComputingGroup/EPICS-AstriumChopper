// This is a wrapper to allow mocking the chopper comms.
#if !defined( CHOPPER_H )
#define CHOPPER_H

#include <string>
#include <gcroot.h>
#include <locale.h>
#include <sstream>
#include <iostream>
#include <msclr/marshal_cppstd.h>

using namespace System::Collections::Generic;

namespace Wrapper
{
	public ref class IChopper abstract
	{
		public:
			virtual System::String^ Calibrate() = 0;
			virtual System::String^ GetStatus(unsigned int channel) = 0;
			virtual System::String^ SetGear(unsigned int channel, int speed) = 0;
			virtual System::String^ SetPhase(unsigned int channel, double phase) = 0;
			virtual System::String^ SetBrake(unsigned int channel) = 0;
	};

	public ref class AstriumChopper : public IChopper {
		private:
			static AstriumComms::Chopper^ chopper;

		public:
			AstriumChopper(System::String^ ip) {
				chopper = gcnew AstriumComms::Chopper(gcnew System::String(ip));
			};

			virtual System::String^ Calibrate() override {
				return chopper->Calibrate();
			};

			virtual System::String^ GetStatus(unsigned int channel) override {
				return chopper->GetStatus(channel);
			};

			virtual System::String^ SetGear(unsigned int channel, int speed) override {
				return chopper->SetGear(channel, speed);
			};

			virtual System::String^ SetPhase(unsigned int channel, double phase) override {
				return chopper->SetPhase(channel, phase);
			};

			virtual System::String^ SetBrake(unsigned int channel) override {
				return chopper->SetBrake(channel);
			};
	};

	public ref class MockChopper : public IChopper {
		private:
			System::String^ acceptString;
			System::String^ rejectString;
			System::String^ state;
			double phase;
			int speed;
		public:
			MockChopper(std::string controllerID);
			virtual System::String^ Calibrate() override;
			virtual System::String^ GetStatus(unsigned int channel) override;
			virtual System::String^ SetGear(unsigned int channel, int speed) override;
			virtual System::String^ SetPhase(unsigned int channel, double phase) override;
			virtual System::String^ SetBrake(unsigned int channel) override;
	};

	// These proxies will allow us to use boost to bind to methods.
	System::String^ GetStatusProxy(gcroot<Wrapper::IChopper^> This, unsigned int channel);
	System::String^ SetGearProxy(gcroot<Wrapper::IChopper^> This, unsigned int channel, int speed);
	System::String^ SetPhaseProxy(gcroot<Wrapper::IChopper^> This, unsigned int channel, double phase);
	System::String^ SetBrakeProxy(gcroot<Wrapper::IChopper^> This, unsigned int channel);
	System::String^ CalibrateProxy(gcroot<Wrapper::IChopper^> This);
}

#endif