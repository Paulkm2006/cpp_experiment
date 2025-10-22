#include <gtest/gtest.h>
#include <memory>
#include <tuple>
#include "Executor.hpp"

namespace adas
{
	bool operator==(const Pose &lhs, const Pose &rhs)
	{
		return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
	}

	TEST(ExecutorTest, should_return_init_pose_without_command)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({0, 0, 'E'});

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTest, should_return_default_pose_without_command)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor());
		const Pose target({0, 0, 'N'});

		ASSERT_EQ(executor->Query(), target);
	}
}