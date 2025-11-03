#pragma once

#include <list>

#include "core/PoseHandler.hpp"

namespace adas
{
	enum class ActionType : uint16_t
	{
		FORWARD_1_STEP = 0,
		BACKWARD_1_STEP,
		TURN_LEFT,
		TURN_RIGHT,
		REVERSE_LEFT,
		REVERSE_RIGHT,
		FAST,
		REVERSE,
	};

	class ActionGroup final
	{
	public:
		ActionGroup() = default;
		~ActionGroup() = default;

		ActionGroup(const std::list<ActionType> &actions) noexcept : actions(actions) {}

		ActionGroup(const ActionGroup &) = default;
		ActionGroup &operator=(const ActionGroup &) = default;

		void PushAction(const ActionType action) noexcept;
		void DoOperate(PoseHandler &poseHandler) const noexcept;

	private:
		std::list<ActionType> actions;
	};
}