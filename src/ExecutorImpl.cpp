#include "ExecutorImpl.hpp"
#include "Command.hpp"

#include <new>
#include <memory>

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
		for (const char &c : command)
		{
			std::unique_ptr<ICommand> cmd;
			if (c == 'M')
			{
				cmd = std::make_unique<MoveCmd>();
			}
			else if (c == 'L')
			{
				cmd = std::make_unique<LeftCmd>();
			}
			else if (c == 'R')
			{
				cmd = std::make_unique<RightCmd>();
			}
			else if (c == 'F')
			{
				cmd = std::make_unique<FastCmd>();
			}
			if (cmd)
			{
				cmd->DoOperate(poseHandler);
			}
		}
	}

} // namespace adas