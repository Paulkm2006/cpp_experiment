#include "ExecutorImpl.hpp"
#include "cmder/CmderFactory.hpp"
#include "core/Singleton.hpp"

#include <algorithm>

namespace adas
{
	ExecutorImpl::ExecutorImpl(const Pose &pose, const ExecutorType executorType) noexcept : poseHandler(pose), executorType(executorType) {}

	Executor *Executor::NewExecutor(const Pose &pose, const ExecutorType executorType) noexcept
	{
		return new (std::nothrow) ExecutorImpl(pose, executorType);
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
						  cmder(this->poseHandler).DoOperate(this->poseHandler);
					  });
	}

} // namespace adas