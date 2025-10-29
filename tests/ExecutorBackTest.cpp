#include <gtest/gtest.h>
#include <memory>
#include "Executor.hpp"
#include "poseEq.hpp"

namespace adas
{
	// B指令 - 倒车模式下的M指令测试
	// M: 在当前朝向上后退一格，朝向不变
	TEST(ExecutorBackTest, should_return_y_minus_1_given_status_is_back_command_is_M_and_facing_is_N)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({0, -1, 'N'});

		executor->Execute("BM");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorBackTest, should_return_x_minus_1_given_status_is_back_command_is_M_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({-1, 0, 'E'});

		executor->Execute("BM");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorBackTest, should_return_y_plus_1_given_status_is_back_command_is_M_and_facing_is_S)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
		const Pose target({0, 1, 'S'});

		executor->Execute("BM");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorBackTest, should_return_x_plus_1_given_status_is_back_command_is_M_and_facing_is_W)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
		const Pose target({1, 0, 'W'});

		executor->Execute("BM");

		ASSERT_EQ(executor->Query(), target);
	}

	// B指令 - 倒车模式下的L指令测试
	// L: 右转90度，位置不变
	TEST(ExecutorBackTest, should_return_facing_E_given_status_is_back_command_is_L_and_facing_is_N)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({0, 0, 'E'});

		executor->Execute("BL");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorBackTest, should_return_facing_S_given_status_is_back_command_is_L_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({0, 0, 'S'});

		executor->Execute("BL");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorBackTest, should_return_facing_W_given_status_is_back_command_is_L_and_facing_is_S)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
		const Pose target({0, 0, 'W'});

		executor->Execute("BL");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorBackTest, should_return_facing_N_given_status_is_back_command_is_L_and_facing_is_W)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
		const Pose target({0, 0, 'N'});

		executor->Execute("BL");

		ASSERT_EQ(executor->Query(), target);
	}

	// B指令 - 倒车模式下的R指令测试
	// R: 左转90度，位置不变
	TEST(ExecutorBackTest, should_return_facing_W_given_status_is_back_command_is_R_and_facing_is_N)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({0, 0, 'W'});

		executor->Execute("BR");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorBackTest, should_return_facing_N_given_status_is_back_command_is_R_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({0, 0, 'N'});

		executor->Execute("BR");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorBackTest, should_return_facing_E_given_status_is_back_command_is_R_and_facing_is_S)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
		const Pose target({0, 0, 'E'});

		executor->Execute("BR");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorBackTest, should_return_facing_S_given_status_is_back_command_is_R_and_facing_is_W)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
		const Pose target({0, 0, 'S'});

		executor->Execute("BR");

		ASSERT_EQ(executor->Query(), target);
	}

	// B+F叠加状态测试
	// M: 倒退2格（一格一格后退）
	TEST(ExecutorBackTest, should_return_y_minus_2_given_status_is_fast_and_back_command_is_M_and_facing_is_N)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({0, -2, 'N'});

		executor->Execute("FBM");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorBackTest, should_return_x_minus_2_given_status_is_fast_and_back_command_is_M_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({-2, 0, 'E'});

		executor->Execute("BFM");

		ASSERT_EQ(executor->Query(), target);
	}

	// B+F叠加状态下的L指令测试
	// L: 先倒退一格，然后右转90度
	TEST(ExecutorBackTest, should_return_y_minus_1_and_facing_E_given_status_is_fast_and_back_command_is_L_and_facing_is_N)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({0, -1, 'E'});

		executor->Execute("FBL");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorBackTest, should_return_x_minus_1_and_facing_S_given_status_is_fast_and_back_command_is_L_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({-1, 0, 'S'});

		executor->Execute("BFL");

		ASSERT_EQ(executor->Query(), target);
	}

	// B+F叠加状态下的R指令测试
	// R: 先倒退一格，然后左转90度
	TEST(ExecutorBackTest, should_return_y_minus_1_and_facing_W_given_status_is_fast_and_back_command_is_R_and_facing_is_N)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({0, -1, 'W'});

		executor->Execute("FBR");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorBackTest, should_return_x_minus_1_and_facing_N_given_status_is_fast_and_back_command_is_R_and_facing_is_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({-1, 0, 'N'});

		executor->Execute("BFR");

		ASSERT_EQ(executor->Query(), target);
	}

	// 测试B指令切换（再接收一次B指令，状态取消）
	TEST(ExecutorBackTest, should_return_y_plus_1_given_command_is_BBM_and_facing_is_N)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({0, 1, 'N'});

		executor->Execute("BBM");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorBackTest, should_return_facing_W_given_command_is_BBL_and_facing_is_N)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({0, 0, 'W'});

		executor->Execute("BBL");

		ASSERT_EQ(executor->Query(), target);
	}

	// 综合测试：倒车模式下的复杂指令序列
	TEST(ExecutorBackTest, should_handle_complex_back_commands)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({0, -1, 'W'});

		executor->Execute("BMBL");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorBackTest, should_handle_fast_back_complex_commands)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({0, -2, 'W'});

		executor->Execute("FBMBL");

		ASSERT_EQ(executor->Query(), target);
	}
}