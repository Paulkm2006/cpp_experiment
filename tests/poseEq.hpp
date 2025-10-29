#pragma once

#include <gtest/gtest.h>
#include <tuple>
#include "Executor.hpp"

namespace adas
{
	inline bool operator==(const Pose &lhs, const Pose &rhs)
	{
		return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
	}
}