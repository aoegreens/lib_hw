#pragma once

#include "GPIOManager.h"

namespace aoe {
namespace hw {

class PinController : public bio::physical::ThreadedPeriodic
{
public:
	PinController();

	virtual ~PinController();

	/**
	 * Per bio::physical::ThreadedPeriodic. See that class (and bio::physical::Periodic) for more info.
	 * @return false when exit requested.
	 */
	virtual bio::Code Peak();

	GPIOManager* GetGPIOManager(
		Pin pin,
		GPIODirection defaultDirection = gpio_direction::Out());

	virtual Voltage ReadGPIOInput(Pin pin);

	virtual GPIOState GetGPIOState(Pin pin);

	virtual GPIOState SetGPIOState(
		Pin pin,
		const GPIOState state
	);

	virtual GPIODirection GetGPIODirection(Pin pin);

protected:
	std::vector< GPIOManager* > m_gpioManagers;
};

} //hw namespace
} //aoe namespace
