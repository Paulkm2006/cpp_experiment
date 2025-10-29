#pragma once

#include "Executor.hpp"

namespace adas
{

	class PoseHandler
	{
	public:
		PoseHandler(const Pose &pose) noexcept;
		PoseHandler(const PoseHandler &) = delete;
		PoseHandler &operator=(const PoseHandler &) = delete;

		void Move(void) noexcept;
		void Left(void) noexcept;
		void Right(void) noexcept;
		void Fast(void) noexcept;
		bool IsFast(void) const noexcept;
		Pose Query(void) const noexcept;

	private:
		Pose pose;
		bool fast{false};
	};
}