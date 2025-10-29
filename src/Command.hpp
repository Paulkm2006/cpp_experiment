#pragma once

#include "ExecutorImpl.hpp"

namespace adas
{
	class ICommand
	{
	public:
		virtual ~ICommand() noexcept = default;
		virtual void DoOperate(ExecutorImpl &executor) const noexcept = 0;
	};

	class MoveCmd final : public ICommand
	{
	public:
		void DoOperate(ExecutorImpl &executor) const noexcept override
		{
			executor.move();
		}
	};
	class LeftCmd final : public ICommand
	{
	public:
		void DoOperate(ExecutorImpl &executor) const noexcept override
		{
			executor.left();
		}
	};
	class RightCmd final : public ICommand
	{
	public:
		void DoOperate(ExecutorImpl &executor) const noexcept override
		{
			executor.right();
		}
	};
	class FastCmd final : public ICommand
	{
	public:
		void DoOperate(ExecutorImpl &executor) const noexcept override
		{
			executor.fast();
		}
	};
}