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

	// 移动指令 (Movement Commands)
	TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({1, 0, 'E'});

		executor->Execute("M");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
		const Pose target({-1, 0, 'W'});

		executor->Execute("M");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({0, 1, 'N'});

		executor->Execute("M");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
		const Pose target({0, -1, 'S'});

		executor->Execute("M");

		ASSERT_EQ(executor->Query(), target);
	}

	// 左转指令 (Left Turn Commands)
	TEST(ExecutorTest, should_return_facing_N_given_command_is_L_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({0, 0, 'N'});

		executor->Execute("L");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTest, should_return_facing_W_given_command_is_L_and_facing_is_N)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({0, 0, 'W'});

		executor->Execute("L");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTest, should_return_facing_S_given_command_is_L_and_facing_is_W)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
		const Pose target({0, 0, 'S'});

		executor->Execute("L");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTest, should_return_facing_E_given_command_is_L_and_facing_is_S)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
		const Pose target({0, 0, 'E'});

		executor->Execute("L");

		ASSERT_EQ(executor->Query(), target);
	}

	// 右转指令 (Right Turn Commands)
	TEST(ExecutorTest, should_return_facing_S_given_command_is_R_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({0, 0, 'S'});

		executor->Execute("R");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTest, should_return_facing_W_given_command_is_R_and_facing_is_S)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
		const Pose target({0, 0, 'W'});

		executor->Execute("R");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTest, should_return_facing_N_given_command_is_R_and_facing_is_W)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
		const Pose target({0, 0, 'N'});

		executor->Execute("R");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTest, should_return_facing_E_given_command_is_R_and_facing_is_N)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({0, 0, 'E'});

		executor->Execute("R");

		ASSERT_EQ(executor->Query(), target);
	}

	// Fast mode related tests
	TEST(ExecutorTest, should_return_x_plus_2_given_status_is_fast_command_is_M_and_facing_is_E)
	{
		// turn on fast mode then move once -> step should be 2 when facing East
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({2, 0, 'E'});

		executor->Execute("FM");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTest, should_return_N_and_x_plus_1_given_status_is_fast_command_is_L_and_facing_is_E)
	{
		// turn on fast, then rotate left (to N) and move once while still fast -> moving north
		// To match the original intent of checking both rotation and movement, use sequence: F L M
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({0, 2, 'N'});

		executor->Execute("FLM");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTest, should_return_S_and_x_plus_1_given_status_is_fast_given_command_is_R_and_facing_is_E)
	{
		// turn on fast, then rotate right (to S) and move once while still fast -> moving south
		// Use sequence: F R M
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({0, -2, 'S'});

		executor->Execute("FRM");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTest, should_return_y_plus_1_given_command_is_FFM_and_facing_is_N)
	{
		// F toggles fast on, second F toggles it off, then M moves by 1
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({0, 1, 'N'});

		executor->Execute("FFM");

		ASSERT_EQ(executor->Query(), target);
	}

}