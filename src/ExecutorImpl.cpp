#include "ExecutorImpl.hpp"
#include "Command.hpp"

#include <new>
#include <memory>
#include <unordered_map>
#include <functional>

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

		std::unordered_map<char, std::function<void(PoseHandler &)>> commandMap;

		commandMap['M'] = MoveCmd();
		commandMap['L'] = LeftCmd();
		commandMap['R'] = RightCmd();
		commandMap['F'] = FastCmd();
		commandMap['B'] = BackCmd();

		for (const char &c : command)
		{
			auto it = commandMap.find(c);
			if (it != commandMap.end())
			{
				it->second(poseHandler);
			}
		}
	}

} // namespace adas