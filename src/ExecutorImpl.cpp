#include "ExecutorImpl.hpp"
#include "CmderFactory.hpp"
#include "Singleton.hpp"

#include <algorithm>

namespace adas
{
	ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose) {}

	Executor *Executor::NewExecutor(const Pose &pose) noexcept
	{
		return new (std::nothrow) ExecutorImpl(pose);
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
						  cmder(this->poseHandler);
					  });
	}

} // namespace adas