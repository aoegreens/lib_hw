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

#pragma once

#include "GPIOManager.h"

namespace aoe {
namespace hw {

class PinController : public bio::physical::ThreadedPeriodic, public bio::log::Writer
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
