#include <gtest/gtest.h>
#include <memory>
#include "Executor.hpp"
#include "poseEq.hpp"

namespace adas
{
	TEST(ExecutorFastTest, should_return_x_plus_2_given_status_is_fast_command_is_M_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({2, 0, 'E'});

		executor->Execute("FM");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorFastTest, should_return_N_and_same_position_given_command_is_FL_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({0, 0, 'N'});

		executor->Execute("FL");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorFastTest, should_return_S_and_same_position_given_command_is_FR_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({0, 0, 'S'});

		executor->Execute("FR");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorFastTest, should_return_N_and_x_plus_1_given_status_is_fast_command_is_L_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({0, 2, 'N'});

		executor->Execute("FLM");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorFastTest, should_return_S_and_x_plus_1_given_status_is_fast_given_command_is_R_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({0, -2, 'S'});

		executor->Execute("FRM");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorFastTest, should_return_y_plus_1_given_command_is_FFM_and_facing_is_N)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({0, 1, 'N'});

		executor->Execute("FFM");

		ASSERT_EQ(executor->Query(), target);
	}
}