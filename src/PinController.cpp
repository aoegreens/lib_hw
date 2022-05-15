#include "aoe/hw/PinController.h"
#include "aoe/hw/macros/Macros.h"
#include <stdexcept>

namespace aoe {
namespace hw {

PinController::PinController()
{
	//@formatter:off
	#if AOE_TARGET_IS_RPI
		if (wiringPiSetup() == -1)
		{
			throw ::std::runtime_error("Failed to setup WiringPi");
		}
	#endif
	//@formatter:on
}

PinController::~PinController()
{
	for (auto man: m_gpioManagers)
	{
		delete man;
	}
	m_gpioManagers.clear();
}

bio::Code PinController::Peak()
{

	return bio::code::Success();
}

GPIOManager* PinController::GetGPIOManager(
	Pin pin,
	GPIODirection defaultDirection
)
{
	for (auto man: m_gpioManagers)
	{
		if (man->GetPin() == pin)
		{
			return man;
		}
	}
	GPIOManager* newManager = new GPIOManager(
		pin,
		defaultDirection
	);
	Sleep(1000); //add delay so hardware can be initialized.
	m_gpioManagers.push_back(newManager);
	return newManager;
}


Voltage PinController::ReadGPIOInput(Pin pin)
{
	return GetGPIOManager(
		pin,
		gpio_direction::In()
	)->ReadInput();
}

GPIOState PinController::GetGPIOState(Pin pin)
{
	return GetGPIOManager(
		pin,
		gpio_direction::Out()
	)->GetState();
}

GPIOState PinController::SetGPIOState(
	Pin pin,
	const GPIOState state
)
{
	return GetGPIOManager(
		pin,
		gpio_direction::Out()
	)->SetState(state);
}

GPIODirection PinController::GetGPIODirection(Pin pin)
{
	return GetGPIOManager(
		pin,
		gpio_direction::Out()
	)->GetDirection();
}

} //hw namespace
} //aoe namespace
