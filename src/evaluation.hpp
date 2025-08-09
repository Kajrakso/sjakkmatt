#pragma once

#include <limits.h>

#include "core/position.hpp"

/* (-32768/2 = -16384) */
constexpr unsigned int VALUE_MATED = (SHRT_MIN/2);

int evaluate(const Position p);
