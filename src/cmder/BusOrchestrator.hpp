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
			actionGroup += GetStepAction(poseHandler);

			actionGroup += OnFast(poseHandler);

			const auto actionType = poseHandler.IsBack() ? ActionType::REVERSE_LEFT : ActionType::TURN_LEFT;
			actionGroup += actionType;

			return actionGroup;
		}
		ActionGroup Right(const PoseHandler &poseHandler) const noexcept override
		{
			ActionGroup actionGroup;

			actionGroup += GetStepAction(poseHandler);

			actionGroup += OnFast(poseHandler);

			const auto actionType = poseHandler.IsBack() ? ActionType::REVERSE_RIGHT : ActionType::TURN_RIGHT;
			actionGroup += actionType;

			return actionGroup;
		}
	};
}