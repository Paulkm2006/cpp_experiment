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

		void move(void) noexcept;
		void left(void) noexcept;
		void right(void) noexcept;
		void fast(void) noexcept;

	private:
		/// @brief The current pose of the executor
		Pose pose;
		bool isFast;
	};
} // namespace adas