#pragma warning(disable : 5045)

#include "ActionGroup.hpp"
#include "CmderFactory.hpp"

#include <vector>
#include <algorithm>

namespace adas
{
	class ForwardAction final
	{
	public:
		void operator()(PoseHandler &poseHandler) noexcept
		{
			poseHandler.Forward();
		}
	};
	class BackwardAction final
	{
	public:
		void operator()(PoseHandler &poseHandler) noexcept
		{
			poseHandler.Backward();
		}
	};
	class LeftAction final
	{
	public:
		void operator()(PoseHandler &poseHandler) noexcept
		{
			poseHandler.Left();
		}
	};
	class RightAction final
	{
	public:
		void operator()(PoseHandler &poseHandler) noexcept
		{
			poseHandler.Right();
		}
	};
	class ReverseLeftAction final
	{
	public:
		void operator()(PoseHandler &poseHandler) noexcept
		{
			poseHandler.Right();
		}
	};
	class ReverseRightAction final
	{
	public:
		void operator()(PoseHandler &poseHandler) noexcept
		{
			poseHandler.Left();
		}
	};
	class FastAction final
	{
	public:
		void operator()(PoseHandler &poseHandler) noexcept
		{
			poseHandler.SetFast();
		}
	};
	class BackAction final
	{
	public:
		void operator()(PoseHandler &poseHandler) noexcept
		{
			poseHandler.SetBack();
		}
	};

	void ActionGroup::PushAction(const ActionType action) noexcept
	{
		actions.push_back(action);
	}

	void ActionGroup::DoOperate(PoseHandler &poseHandler) const noexcept
	{
		static std::vector<std::function<void(PoseHandler &)>> actionMap{
			ForwardAction(),
			BackwardAction(),
			LeftAction(),
			RightAction(),
			ReverseLeftAction(),
			ReverseRightAction(),
			FastAction(),
			BackAction()};
		std::for_each(actions.begin(), actions.end(),
					  [&poseHandler](const ActionType action) noexcept
					  {
						  const auto index = static_cast<std::size_t>(action);
						  if (index < actionMap.size())
						  {
							  actionMap[index](poseHandler);
						  }
					  });
	}

	ActionGroup &ActionGroup::operator+=(const ActionGroup &other) noexcept
	{
		actions.insert(actions.end(), other.actions.begin(), other.actions.end());
		return *this;
	}
}