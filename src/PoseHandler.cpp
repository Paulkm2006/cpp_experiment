#include "PoseHandler.hpp"

namespace adas
{

	PoseHandler::PoseHandler(const Pose &pose) noexcept : pose(pose), fast(false)
	{
	}

	void PoseHandler::Move(void) noexcept
	{
		int step = fast ? 2 : 1;
		switch (pose.heading)
		{
		case 'N':
			pose.y += step;
			break;
		case 'E':
			pose.x += step;
			break;
		case 'S':
			pose.y -= step;
			break;
		case 'W':
			pose.x -= step;
			break;
		default:
			break;
		}
	}

	void PoseHandler::Left(void) noexcept
	{
		switch (pose.heading)
		{
		case 'N':
			pose.heading = 'W';
			break;
		case 'W':
			pose.heading = 'S';
			break;
		case 'S':
			pose.heading = 'E';
			break;
		case 'E':
			pose.heading = 'N';
			break;
		default:
			break;
		}
	}

	void PoseHandler::Right(void) noexcept
	{
		switch (pose.heading)
		{
		case 'N':
			pose.heading = 'E';
			break;
		case 'E':
			pose.heading = 'S';
			break;
		case 'S':
			pose.heading = 'W';
			break;
		case 'W':
			pose.heading = 'N';
			break;
		default:
			break;
		}
	}

	void PoseHandler::Fast(void) noexcept
	{
		fast = !fast;
	}

	bool PoseHandler::IsFast(void) const noexcept
	{
		return fast;
	}

	Pose PoseHandler::Query(void) const noexcept
	{
		return pose;
	}
}