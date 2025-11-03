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

			actionGroup += OnFast(poseHandler);

			const auto actionType = poseHandler.IsBack() ? ActionType::REVERSE_RIGHT : ActionType::TURN_RIGHT;
			actionGroup.PushAction(actionType);

			return actionGroup;
		}
	};
}