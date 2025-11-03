#pragma once

#include "core/PoseHandler.hpp"
#include "cmder/CmderOrchestrator.hpp"

namespace adas
{

	class MoveCmd final
	{
	public:
		ActionGroup operator()(PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) noexcept
		{
			return orchestrator.Move(poseHandler);
		}
	};
	class LeftCmd final
	{
	public:
		ActionGroup operator()(PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) noexcept
		{
			return orchestrator.Left(poseHandler);
		}
	};
	class RightCmd final
	{
	public:
		ActionGroup operator()(PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) noexcept
		{
			return orchestrator.Right(poseHandler);
		}
	};
	class FastCmd final
	{
	public:
		ActionGroup operator()([[maybe_unused]] PoseHandler &poseHandler, [[maybe_unused]] const CmderOrchestrator &orchestrator) noexcept
		{
			return ActionGroup{{ActionType::FAST}};
		}
	};
	class BackCmd final
	{
	public:
		ActionGroup operator()([[maybe_unused]] PoseHandler &poseHandler, [[maybe_unused]] const CmderOrchestrator &orchestrator) noexcept
		{
			return ActionGroup{{ActionType::REVERSE}};
		}
	};

	class TurnRoundCmd final
	{
	public:
		ActionGroup operator()(PoseHandler &poseHandler, const CmderOrchestrator &orchestrator) noexcept
		{
			return orchestrator.TurnRound(poseHandler);
		}
	};
}