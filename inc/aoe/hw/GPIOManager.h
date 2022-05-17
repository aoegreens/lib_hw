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
