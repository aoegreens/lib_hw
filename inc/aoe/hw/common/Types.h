#pragma once

#include <bio.h>

namespace aoe {
namespace hw {

typedef float Voltage;

typedef uint8_t Pin;

BIO_ID_WITH_PERSPECTIVE(GPIOState,
	uint8_t)

BIO_ID_WITH_PERSPECTIVE(GPIODirection,
	uint8_t)

} //hw namespace
} //aoe namespace
