#pragma once

#include "cmder/NormalOrchestrator.hpp"

namespace adas
{

	class BusOrchestrator : public NormalOrchestrator
	{
	public:
		ActionGroup Left(const PoseHandler &poseHandler) const noexcept override
		{
			ActionGroup actionGroup;

			actionGroup.PushAction(ActionType::FORWARD_1_STEP);

			actionGroup += OnFast(poseHandler);

			const auto actionType = poseHandler.IsBack() ? ActionType::REVERSE_LEFT : ActionType::TURN_LEFT;
			actionGroup.PushAction(actionType);

			return actionGroup;
		}
		ActionGroup Right(const PoseHandler &poseHandler) const noexcept override
		{
			ActionGroup actionGroup;

			actionGroup += OnFast(poseHandler);

			const auto actionType = poseHandler.IsBack() ? ActionType::REVERSE_RIGHT : ActionType::TURN_RIGHT;
			actionGroup.PushAction(actionType);

			return actionGroup;
		}
	};
}