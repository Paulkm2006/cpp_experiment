#pragma once

#include "cmder/ActionGroup.hpp"

namespace adas
{

	class CmderOrchestrator
	{
	public:
		virtual ~CmderOrchestrator(void) = default;

		virtual ActionGroup Move(const PoseHandler &poseHandler) const noexcept = 0;
		virtual ActionGroup Left(const PoseHandler &poseHandler) const noexcept = 0;
		virtual ActionGroup Right(const PoseHandler &poseHandler) const noexcept = 0;
		virtual ActionGroup TurnRound(const PoseHandler &poseHandler) const noexcept = 0;
	};

}