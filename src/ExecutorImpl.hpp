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

		class MoveCmd final
		{
		public:
			void DoOperate(ExecutorImpl &executor) const noexcept
			{
				executor.move();
			}
		};
		class LeftCmd final
		{
		public:
			void DoOperate(ExecutorImpl &executor) const noexcept
			{
				executor.left();
			}
		};
		class RightCmd final
		{
		public:
			void DoOperate(ExecutorImpl &executor) const noexcept
			{
				executor.right();
			}
		};
	};

} // namespace adas