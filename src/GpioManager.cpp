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

#include "aoe/hw/GPIOManager.h"
#include "aoe/hw/macros/Macros.h"

namespace aoe {
namespace hw {

GPIOManager::GPIOManager(
	Pin pin,
	GPIODirection direction
)
	:
	m_pin(pin),
	m_initialized(false),
	m_state(GPIOStatePerspective::InvalidId()),
	m_direction(direction)
{
	Initialize();
}

GPIOManager::~GPIOManager()
{

}

Pin GPIOManager::GetPin() const
{
	return m_pin;
}

GPIODirection GPIOManager::GetDirection() const
{
	return m_direction;
}

bool GPIOManager::HasBeenInitialized() const
{
	return m_initialized;
}

void GPIOManager::Initialize()
{
	if (m_direction == gpio_direction::In())
	{
		//@formatter:off
		#if AOE_TARGET_IS_RPI
			pinMode(
				m_pin,
				INPUT
			);
		#endif
		//@formatter:on
		m_initialized = true;
	}
	else if (m_direction == gpio_direction::Out())
	{
		//@formatter:off
		#if AOE_TARGET_IS_RPI
			pinMode(
				m_pin,
				OUTPUT
			);
			digitalWrite(
				m_pin,
				LOW
			);
		#endif
		//@formatter:on
		m_state = gpio_state::Off();
		m_initialized = true;
	}
	else
	{
		m_initialized = false;
	}
}

Voltage GPIOManager::ReadInput()
{
	if (m_direction != gpio_direction::In())
	{
		return 0.0f;
	}

	//TODO
	return 0.0f;
}

GPIOState GPIOManager::GetState() const
{
	return m_state;
}

GPIOState GPIOManager::SetState(const GPIOState state)
{
	if (m_direction != gpio_direction::Out())
	{
		return m_state;
	}

	if (state == gpio_state::On())
	{
		//@formatter:off
		#if AOE_TARGET_IS_RPI
			digitalWrite(
				m_pin,
				HIGH
			);
		#endif
		//@formatter:on
		m_state = gpio_state::On();
	}
	else if (state == gpio_state::Off())
	{
		//@formatter:off
		#if AOE_TARGET_IS_RPI
			digitalWrite(
				m_pin,
				LOW
			);
		#endif
		//@formatter:on
		m_state = gpio_state::Off();
	}
	else if (state == gpio_state::Toggle())
	{
		if (m_state == gpio_state::On())
		{
			return SetState(gpio_state::Off());
		}
		else if (m_state == gpio_state::Off())
		{
			return SetState(gpio_state::On());
		}
	}
	else
	{
		return GPIOStatePerspective::Instance().InvalidId();
	}
	return m_state;
}

} //hw namespace
} //aoe namespace
