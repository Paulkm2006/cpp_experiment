#include "ExecutorImpl.hpp"
#include "cmder/CmderFactory.hpp"
#include "cmder/NormalOrchestrator.hpp"
#include "cmder/SportsCarOrchestrator.hpp"
#include "cmder/BusOrchestrator.hpp"
#include "core/Singleton.hpp"

#include <algorithm>

namespace adas
{
	ExecutorImpl::ExecutorImpl(const Pose &pose, CmderOrchestrator *orchestrator) noexcept : poseHandler(pose), orchestrator(orchestrator) {}

	Executor *Executor::NewExecutor(const Pose &pose, const ExecutorType executorType) noexcept
	{
		CmderOrchestrator *orchestrator{nullptr};

		switch (executorType)
		{
		case ExecutorType::NORMAL:
			orchestrator = new NormalOrchestrator();
			break;
		case ExecutorType::SPORTS_CAR:
			orchestrator = new SportsCarOrchestrator();
			break;
		case ExecutorType::BUS:
			orchestrator = new BusOrchestrator();
			break;
		default:
			orchestrator = new NormalOrchestrator();
			break;
		}

		return new ExecutorImpl(pose, orchestrator);
	}

	Pose ExecutorImpl::Query(void) const noexcept
	{
		return poseHandler.Query();
	}

	void ExecutorImpl::Execute(const std::string &command) noexcept
	{

		const auto cmders = Singleton<CmderFactory>::Instance().GetCmders(command);

		std::for_each(cmders.begin(), cmders.end(),
					  [this](const Cmder &cmder) noexcept
					  {
						  cmder(this->poseHandler, *orchestrator).DoOperate(this->poseHandler);
					  });
	}

} // namespace adas