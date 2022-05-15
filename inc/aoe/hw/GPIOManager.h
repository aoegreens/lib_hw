#pragma once

#include "aoe/hw/common/Types.h"
#include "aoe/hw/common/GPIODirection.h"
#include "aoe/hw/common/GPIOState.h"

namespace aoe {
namespace hw {

class GPIOManager
{
public:
	GPIOManager(
		Pin pin,
		GPIODirection direction = gpio_direction::Out());

	virtual ~GPIOManager();

	virtual Pin GetPin() const;

	virtual GPIODirection GetDirection() const;

	virtual bool HasBeenInitialized() const;

	virtual void Initialize();

	virtual float ReadInput();

	virtual GPIOState GetState() const;

	virtual GPIOState SetState(const GPIOState state);

protected:
	uint8_t m_pin;
	bool m_initialized;
	GPIOState m_state;
	GPIODirection m_direction;
};

} //hw namespace
} //aoe namespace
