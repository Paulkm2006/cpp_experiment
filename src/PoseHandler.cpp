#include "PoseHandler.hpp"

namespace adas
{

	PoseHandler::PoseHandler(const Pose &pose) noexcept : pose(pose), fast(false), back(false)
	{
	}

	void PoseHandler::Move(void) noexcept
	{
		int step = fast ? 2 : 1;
		int direction = back ? -1 : 1;

		for (int i = 0; i < step; ++i)
		{
			switch (pose.heading)
			{
			case 'N':
				pose.y += direction;
				break;
			case 'E':
				pose.x += direction;
				break;
			case 'S':
				pose.y -= direction;
				break;
			case 'W':
				pose.x -= direction;
				break;
			default:
				break;
			}
		}
	}

	void PoseHandler::Left(void) noexcept
	{
		if (back)
		{
			if (fast)
			{
				switch (pose.heading)
				{
				case 'N':
					pose.y -= 1;
					break;
				case 'E':
					pose.x -= 1;
					break;
				case 'S':
					pose.y += 1;
					break;
				case 'W':
					pose.x += 1;
					break;
				default:
					break;
				}
			}
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
		else
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
	}

	void PoseHandler::Right(void) noexcept
	{
		if (back)
		{
			if (fast)
			{
				switch (pose.heading)
				{
				case 'N':
					pose.y -= 1;
					break;
				case 'E':
					pose.x -= 1;
					break;
				case 'S':
					pose.y += 1;
					break;
				case 'W':
					pose.x += 1;
					break;
				default:
					break;
				}
			}
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
		else
		{
			// Normal right turn
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
		return pose;
	}
}