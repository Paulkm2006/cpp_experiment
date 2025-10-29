#include "ExecutorImpl.hpp"
#include "Command.hpp"

#include <new>
#include <memory>
#include <unordered_map>

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

		std::unordered_map<char, std::unique_ptr<ICommand>> commandMap;

		commandMap['M'] = std::make_unique<MoveCmd>();
		commandMap['L'] = std::make_unique<LeftCmd>();
		commandMap['R'] = std::make_unique<RightCmd>();
		commandMap['F'] = std::make_unique<FastCmd>();
		commandMap['B'] = std::make_unique<BackCmd>();

		for (const char &c : command)
		{
			auto it = commandMap.find(c);
			if (it != commandMap.end())
			{
				it->second->DoOperate(poseHandler);
			}
		}
	}

} // namespace adas