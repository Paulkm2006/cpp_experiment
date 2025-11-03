#pragma once

#include "core/PoseHandler.hpp"
#include "cmder/ActionGroup.hpp"

namespace adas
{

	class MoveCmd final
	{
	public:
		ActionGroup operator()(PoseHandler &poseHandler) noexcept
		{
			ActionGroup actionGroup;

			const auto actionType = poseHandler.IsBack() ? ActionType::BACKWARD_1_STEP : ActionType::FORWARD_1_STEP;

			if (poseHandler.IsFast())
			{
				actionGroup.PushAction(actionType);
			}
			actionGroup.PushAction(actionType);

			return actionGroup;
		}
	};
	class LeftCmd final
	{
	public:
		ActionGroup operator()(PoseHandler &poseHandler) noexcept
		{
			ActionGroup actionGroup;
			if (poseHandler.IsBack() && poseHandler.IsFast())
			{
				actionGroup.PushAction(ActionType::BACKWARD_1_STEP);
			}
			const auto actionType = poseHandler.IsBack() ? ActionType::REVERSE_LEFT : ActionType::TURN_LEFT;
			actionGroup.PushAction(actionType);
			return actionGroup;
		}
	};
	class RightCmd final
	{
	public:
		ActionGroup operator()(PoseHandler &poseHandler) noexcept
		{
			ActionGroup actionGroup;
			if (poseHandler.IsBack() && poseHandler.IsFast())
			{
				actionGroup.PushAction(ActionType::BACKWARD_1_STEP);
			}
			const auto actionType = poseHandler.IsBack() ? ActionType::REVERSE_RIGHT : ActionType::TURN_RIGHT;
			actionGroup.PushAction(actionType);
			return actionGroup;
		}
	};
	class FastCmd final
	{
	public:
		ActionGroup operator()([[maybe_unused]] PoseHandler &poseHandler) noexcept
		{
			ActionGroup actionGroup;
			actionGroup.PushAction(ActionType::FAST);
			return actionGroup;
		}
	};
	class BackCmd final
	{
	public:
		ActionGroup operator()([[maybe_unused]] PoseHandler &poseHandler) noexcept
		{
			ActionGroup actionGroup;
			actionGroup.PushAction(ActionType::REVERSE);
			return actionGroup;
		}
	};

	class TurnRoundCmd final
	{
	public:
		ActionGroup operator()(PoseHandler &poseHandler) noexcept
		{
			if (poseHandler.IsFast())
			{
				return ActionGroup({ActionType::FORWARD_1_STEP,
									ActionType::TURN_LEFT,
									ActionType::FORWARD_1_STEP,
									ActionType::TURN_LEFT});
			}
			else
			{
				return ActionGroup({ActionType::TURN_LEFT,
									ActionType::FORWARD_1_STEP,
									ActionType::TURN_LEFT});
			}
		}
	};
}