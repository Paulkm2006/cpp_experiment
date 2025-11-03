#pragma once

#include "cmder/NormalOrchestrator.hpp"

namespace adas
{

	class SportsCarOrchestrator : public NormalOrchestrator
	{
	public:
		ActionGroup Move(const PoseHandler &poseHandler) const noexcept override
		{
			ActionGroup actionGroup;

			actionGroup += OnFast(poseHandler) * 2;

			actionGroup += ActionGroup{{GetStepAction(poseHandler)}} * 2;

			return actionGroup;
		}

		ActionGroup Left(const PoseHandler &poseHandler) const noexcept override
		{
			ActionGroup actionGroup;

			actionGroup += OnFast(poseHandler);

			const auto actionType = poseHandler.IsBack() ? ActionType::REVERSE_LEFT : ActionType::TURN_LEFT;
			actionGroup += actionType;

			actionGroup += GetStepAction(poseHandler);

			return actionGroup;
		}

		ActionGroup Right(const PoseHandler &poseHandler) const noexcept override
		{
			ActionGroup actionGroup;

			actionGroup += OnFast(poseHandler);

			const auto actionType = poseHandler.IsBack() ? ActionType::REVERSE_RIGHT : ActionType::TURN_RIGHT;

			actionGroup += actionType;

			actionGroup += GetStepAction(poseHandler);

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
	};

}