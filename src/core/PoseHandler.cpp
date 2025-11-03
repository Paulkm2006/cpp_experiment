#include "PoseHandler.hpp"

namespace adas
{

	PoseHandler::PoseHandler(const Pose &pose) noexcept : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading)), fast(false), back(false)
	{
	}

	void PoseHandler::Forward(void) noexcept
	{
		point += facing->Move();
	}
	void PoseHandler::Backward(void) noexcept
	{
		point -= facing->Move();
	}

	void PoseHandler::Left(void) noexcept
	{
		facing = &facing->LeftOne();
	}

	void PoseHandler::Right(void) noexcept
	{

		facing = &facing->RightOne();
	}

	void PoseHandler::SetFast(void) noexcept
	{
		fast = !fast;
	}

	void PoseHandler::SetBack(void) noexcept
	{
		back = !back;
	}

	bool PoseHandler::IsFast(void) const noexcept
	{
		return fast;
	}

	bool PoseHandler::IsBack(void) const noexcept
	{
		return back;
	}

	Pose PoseHandler::Query(void) const noexcept
	{
		return {point.GetX(), point.GetY(), facing->GetHeading()};
	}
}