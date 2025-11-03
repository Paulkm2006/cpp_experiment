#pragma once

#include "cmder/CmderOrchestrator.hpp"

namespace adas
{

	class NormalOrchestrator : public CmderOrchestrator
	{
	public:
		ActionGroup Move(const PoseHandler &poseHandler) const noexcept override
		{
			ActionGroup actionGroup;

			actionGroup += OnFast(poseHandler);

			actionGroup += GetStepAction(poseHandler);

			return actionGroup;
		}
		ActionGroup Left(const PoseHandler &poseHandler) const noexcept override
		{
			ActionGroup actionGroup;

			actionGroup += OnReverseFast(poseHandler);

			const auto actionType = poseHandler.IsBack() ? ActionType::REVERSE_LEFT : ActionType::TURN_LEFT;
			actionGroup += actionType;

			return actionGroup;
		}
		ActionGroup Right(const PoseHandler &poseHandler) const noexcept override
		{
			ActionGroup actionGroup;

			actionGroup += OnReverseFast(poseHandler);

			const auto actionType = poseHandler.IsBack() ? ActionType::REVERSE_RIGHT : ActionType::TURN_RIGHT;
			actionGroup += actionType;

			return actionGroup;
		}
		ActionGroup TurnRound(const PoseHandler &poseHandler) const noexcept override
		{
			ActionGroup actionGroup;

			actionGroup += OnFast(poseHandler);

			actionGroup += ActionType::TURN_LEFT;
			actionGroup += ActionType::FORWARD_1_STEP;
			actionGroup += ActionType::TURN_LEFT;

			return actionGroup;
		}

	protected:
		ActionType GetStepAction(const PoseHandler &poseHandler) const noexcept
		{
			return poseHandler.IsBack() ? ActionType::BACKWARD_1_STEP : ActionType::FORWARD_1_STEP;
		}
		ActionGroup OnFast(const PoseHandler &poseHandler) const noexcept
		{
			if (poseHandler.IsFast())
			{
				return ActionGroup{{GetStepAction(poseHandler)}};
			}
			return ActionGroup{};
		}
		ActionGroup OnReverseFast(const PoseHandler &poseHandler) const noexcept
		{
			if (poseHandler.IsBack())
			{
				return OnFast(poseHandler);
			}
			return ActionGroup{};
		}
	};

} // namespace adas