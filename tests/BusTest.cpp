#include <gtest/gtest.h>
#include <memory>
#include "Executor.hpp"
#include "poseEq.hpp"

namespace adas
{
	// 测试输入: BM
	TEST(BusTest, should_return_x_minus_1_given_command_is_BM_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, ExecutorType::BUS));
		const Pose target({-1, 0, 'E'});

		executor->Execute("BM");

		ASSERT_EQ(executor->Query(), target);
	}

	// 测试输入: FM
	TEST(BusTest, should_return_x_plus_2_given_command_is_FM_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, ExecutorType::BUS));
		const Pose target({2, 0, 'E'});

		executor->Execute("FM");

		ASSERT_EQ(executor->Query(), target);
	}

	// 测试输入: FBM
	TEST(BusTest, should_return_x_minus_2_given_command_is_FBM_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, ExecutorType::BUS));
		const Pose target({-2, 0, 'E'});

		executor->Execute("FBM");

		ASSERT_EQ(executor->Query(), target);
	}

	// 测试输入: L
	TEST(BusTest, should_return_x_plus_1_and_facing_N_given_command_is_L_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, ExecutorType::BUS));
		const Pose target({1, 0, 'N'});

		executor->Execute("L");

		ASSERT_EQ(executor->Query(), target);
	}

	// 测试输入: BL
	TEST(BusTest, should_return_x_minus_1_and_facing_S_given_command_is_BL_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, ExecutorType::BUS));
		const Pose target({-1, 0, 'S'});

		executor->Execute("BL");

		ASSERT_EQ(executor->Query(), target);
	}

	// 测试输入: FL
	TEST(BusTest, should_return_x_plus_2_and_facing_N_given_command_is_FL_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, ExecutorType::BUS));
		const Pose target({2, 0, 'N'});

		executor->Execute("FL");

		ASSERT_EQ(executor->Query(), target);
	}

	// 测试输入: FBL
	TEST(BusTest, should_return_x_minus_2_and_facing_S_given_command_is_FBL_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, ExecutorType::BUS));
		const Pose target({-2, 0, 'S'});

		executor->Execute("FBL");

		ASSERT_EQ(executor->Query(), target);
	}

	// 测试输入: R
	TEST(BusTest, should_return_x_plus_1_and_facing_S_given_command_is_R_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, ExecutorType::BUS));
		const Pose target({1, 0, 'S'});

		executor->Execute("R");

		ASSERT_EQ(executor->Query(), target);
	}

	// 测试输入: BR
	TEST(BusTest, should_return_x_minus_1_and_facing_N_given_command_is_BR_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, ExecutorType::BUS));
		const Pose target({-1, 0, 'N'});

		executor->Execute("BR");

		ASSERT_EQ(executor->Query(), target);
	}

	// 测试输入: FR
	TEST(BusTest, should_return_x_plus_2_and_facing_S_given_command_is_FR_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, ExecutorType::BUS));
		const Pose target({2, 0, 'S'});

		executor->Execute("FR");

		ASSERT_EQ(executor->Query(), target);
	}

	// 测试输入: FBR
	TEST(BusTest, should_return_x_minus_2_and_facing_N_given_command_is_FBR_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}, ExecutorType::BUS));
		const Pose target({-2, 0, 'N'});

		executor->Execute("FBR");

		ASSERT_EQ(executor->Query(), target);
	}

}
