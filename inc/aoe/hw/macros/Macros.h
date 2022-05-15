#pragma once

#include <bio.h>

#include "Target.h"

#define AOE_GPIO_STATE_FUNCTION_BODY(functionName)                             \
BIO_ID_FUNCTION_BODY(                                                          \
    functionName,                                                              \
    ::aoe::hw::GPIOStatePerspective::Instance(),                               \
    ::aoe::hw::GPIOState)

#define AOE_GPIO_DIRECTION_FUNCTION_BODY(functionName)                         \
BIO_ID_FUNCTION_BODY(                                                          \
    functionName,                                                              \
    ::aoe::hw::GPIODirectionPerspective::Instance(),                           \
    ::aoe::hw::GPIODirection)
