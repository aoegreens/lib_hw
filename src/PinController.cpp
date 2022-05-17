// This file is a part of the AOE Greens code base.
// AOE Greens has provided this code to you in the hopes of
// making sustainable food production a world-wide reality.
// For more information on our open source software and how to reach us,
// please visit https://aoegreens.com/about.
//
// Copyright (C) 2022 AOE GREENS LLC and its founders:
// Taylor Parrish and Séon O'Shannon
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>

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

	BIO_LOG_DEBUG("New PinController created.")
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
	BIO_LOG_DEBUG("Refreshing PinController")
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
	BIO_LOG_DEBUG("Reading pin %u", pin)
	return GetGPIOManager(
		pin,
		gpio_direction::In()
	)->ReadInput();
}

GPIOState PinController::GetGPIOState(Pin pin)
{
	GPIOState ret = GetGPIOManager(
		pin,
		gpio_direction::Out()
	)->GetState();
	BIO_LOG_DEBUG("Read pin %u as %s", pin, GPIOStatePerspective::Instance().GetNameFromId(ret))
	return ret;
}

GPIOState PinController::SetGPIOState(
	Pin pin,
	const GPIOState state
)
{
	GPIOState ret = GetGPIOManager(
		pin,
		gpio_direction::Out()
	)->SetState(state);
	BIO_LOG_DEBUG("Set pin %u to %s", pin, GPIOStatePerspective::Instance().GetNameFromId(ret))
	return ret;
}

GPIODirection PinController::GetGPIODirection(Pin pin)
{
	GPIODirection ret = GetGPIOManager(
		pin,
		gpio_direction::Out()
	)->GetDirection();
	BIO_LOG_DEBUG("Direction of pin %u is %s", pin, GPIODirectionPerspective::Instance().GetNameFromId(ret))
	return ret;
}

} //hw namespace
} //aoe namespace
