#include <gtest/gtest.h>
#include <memory>
#include "Executor.hpp"
#include "poseEq.hpp"

namespace adas
{

	// TR (Turn Round) Command Tests - Normal Speed
	TEST(ExecutorTurnRoundTest, should_turn_around_and_move_forward_given_TR_and_facing_N)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({-1, 0, 'S'});

		executor->Execute("TR");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTurnRoundTest, should_turn_around_and_move_forward_given_TR_and_facing_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({0, 1, 'W'});

		executor->Execute("TR");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTurnRoundTest, should_turn_around_and_move_forward_given_TR_and_facing_S)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
		const Pose target({1, 0, 'N'});

		executor->Execute("TR");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTurnRoundTest, should_turn_around_and_move_forward_given_TR_and_facing_W)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
		const Pose target({0, -1, 'E'});

		executor->Execute("TR");

		ASSERT_EQ(executor->Query(), target);
	}

	// TR (Turn Round) Command Tests - Fast Speed
	TEST(ExecutorTurnRoundTest, should_turn_around_with_extra_forward_step_given_TR_F_and_facing_N)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
		const Pose target({-1, 1, 'S'});

		executor->Execute("FTR");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTurnRoundTest, should_turn_around_with_extra_forward_step_given_TR_F_and_facing_E)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
		const Pose target({1, 1, 'W'});

		executor->Execute("FTR");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTurnRoundTest, should_turn_around_with_extra_forward_step_given_TR_F_and_facing_S)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
		const Pose target({1, -1, 'N'});

		executor->Execute("FTR");

		ASSERT_EQ(executor->Query(), target);
	}

	TEST(ExecutorTurnRoundTest, should_turn_around_with_extra_forward_step_given_TR_F_and_facing_W)
	{
		std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
		const Pose target({-1, -1, 'E'});

		executor->Execute("FTR");

		ASSERT_EQ(executor->Query(), target);
	}

}