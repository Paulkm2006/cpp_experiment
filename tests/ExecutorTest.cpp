#include <gtest/gtest.h>
#include <memory>
#include "Executor.hpp"
#include "poseEq.hpp"

namespace adas
{

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

}