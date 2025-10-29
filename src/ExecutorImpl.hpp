#pragma once

#include "Executor.hpp"
#include "PoseHandler.hpp"
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

		void Execute(const std::string &command) noexcept override;
		Pose Query(void) const noexcept override;

	private:
		PoseHandler poseHandler;
	};
} // namespace adas