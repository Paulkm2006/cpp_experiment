#pragma once

#include "Executor.hpp"
#include "core/PoseHandler.hpp"
#include "cmder/CmderOrchestrator.hpp"
#include <memory>

namespace adas
{
	class ExecutorImpl : public Executor
	{
	public:
		explicit ExecutorImpl(const Pose &pose, CmderOrchestrator *orchestrator) noexcept;
		~ExecutorImpl() noexcept = default;

		ExecutorImpl(const ExecutorImpl &) = delete;
		ExecutorImpl &operator=(const ExecutorImpl &) = delete;

		void Execute(const std::string &command) noexcept override;
		Pose Query(void) const noexcept override;

	private:
		PoseHandler poseHandler;
		ExecutorType executorType;
		std::unique_ptr<CmderOrchestrator> orchestrator;
	};
} // namespace adas