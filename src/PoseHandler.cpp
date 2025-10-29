#include "PoseHandler.hpp"

namespace adas
{

	PoseHandler::PoseHandler(const Pose &pose) noexcept : point(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading)), fast(false), back(false)
	{
	}

	void PoseHandler::Move(void) noexcept
	{
		if (back)
		{
			point -= facing->Move();
			if (fast)
			{
				point -= facing->Move();
			}
			return;
		}
		else
		{
			point += facing->Move();
			if (fast)
			{
				point += facing->Move();
			}
		}
	}

	void PoseHandler::Left(void) noexcept
	{
		if (back)
		{
			if (fast)
			{
				point -= facing->Move();
			}
			facing = &facing->RightOne();
		}
		else
		{
			facing = &facing->LeftOne();
		}
	}

	void PoseHandler::Right(void) noexcept
	{
		if (back)
		{
			if (fast)
			{
				point -= facing->Move();
			}
			facing = &facing->LeftOne();
		}
		else
		{
			facing = &facing->RightOne();
		}
	}

	void PoseHandler::Fast(void) noexcept
	{
		fast = !fast;
	}

	void PoseHandler::Back(void) noexcept
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