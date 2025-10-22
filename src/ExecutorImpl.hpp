#pragma once

#include "Executor.hpp"
#include <string>

namespace adas
{
	class ExecutorImpl : public Executor
	{
	public:
		explicit ExecutorImpl(const Pose &pose) noexcept;
		~ExecutorImpl() noexcept = default;

		ExecutorImpl(const ExecutorImpl &) = delete;
		ExecutorImpl &operator=(const ExecutorImpl &) = delete;

		Pose Query(void) const noexcept override;
		void Execute(const std::string &command) noexcept override;

	private:
		/// @brief The current pose of the executor
		Pose pose;
		bool isFast;

		void move(void) noexcept;
		void left(void) noexcept;
		void right(void) noexcept;

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
	};

} // namespace adas