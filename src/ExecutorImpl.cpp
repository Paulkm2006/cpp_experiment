#include "ExecutorImpl.hpp"

#include <new>
#include <memory>

namespace adas
{
	ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : pose(pose), isFast(false) {}

	Pose ExecutorImpl::Query(void) const noexcept
	{
		return pose;
	}

	Executor *Executor::NewExecutor(const Pose &pose) noexcept
	{
		return new (std::nothrow) ExecutorImpl(pose);
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
				cmd->DoOperate(*this);
			}
		}
	}

	void ExecutorImpl::move(void) noexcept
	{
		int step = isFast ? 2 : 1;
		switch (pose.heading)
		{
		case 'N':
			pose.y += step;
			break;
		case 'E':
			pose.x += step;
			break;
		case 'S':
			pose.y -= step;
			break;
		case 'W':
			pose.x -= step;
			break;
		default:
			break;
		}
	}

	void ExecutorImpl::left(void) noexcept
	{
		switch (pose.heading)
		{
		case 'N':
			pose.heading = 'W';
			break;
		case 'W':
			pose.heading = 'S';
			break;
		case 'S':
			pose.heading = 'E';
			break;
		case 'E':
			pose.heading = 'N';
			break;
		default:
			break;
		}
	}

	void ExecutorImpl::right(void) noexcept
	{
		switch (pose.heading)
		{
		case 'N':
			pose.heading = 'E';
			break;
		case 'E':
			pose.heading = 'S';
			break;
		case 'S':
			pose.heading = 'W';
			break;
		case 'W':
			pose.heading = 'N';
			break;
		default:
			break;
		}
	}

	void ExecutorImpl::fast(void) noexcept
	{
		isFast = !isFast;
	}
} // namespace adas