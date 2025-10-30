#pragma once

#include "PoseHandler.hpp"

namespace adas
{

	class MoveCmd final
	{
	public:
		void operator()(PoseHandler &poseHandler) noexcept
		{
			poseHandler.Move();
		}
	};
	class LeftCmd final
	{
	public:
		void operator()(PoseHandler &poseHandler) noexcept
		{
			poseHandler.Left();
		}
	};
	class RightCmd final
	{
	public:
		void operator()(PoseHandler &poseHandler) noexcept
		{
			poseHandler.Right();
		}
	};
	class FastCmd final
	{
	public:
		void operator()(PoseHandler &poseHandler) noexcept
		{
			poseHandler.Fast();
		}
	};
	class BackCmd final
	{
	public:
		void operator()(PoseHandler &poseHandler) noexcept
		{
			poseHandler.Back();
		}
	};
}