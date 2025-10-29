#pragma once

#include "PoseHandler.hpp"

namespace adas
{
	class ICommand
	{
	public:
		virtual ~ICommand() noexcept = default;
		virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
	};

	class MoveCmd final : public ICommand
	{
	public:
		void DoOperate(PoseHandler &poseHandler) const noexcept override
		{
			poseHandler.Move();
		}
	};
	class LeftCmd final : public ICommand
	{
	public:
		void DoOperate(PoseHandler &poseHandler) const noexcept override
		{
			poseHandler.Left();
		}
	};
	class RightCmd final : public ICommand
	{
	public:
		void DoOperate(PoseHandler &poseHandler) const noexcept override
		{
			poseHandler.Right();
		}
	};
	class FastCmd final : public ICommand
	{
	public:
		void DoOperate(PoseHandler &poseHandler) const noexcept override
		{
			poseHandler.Fast();
		}
	};
}