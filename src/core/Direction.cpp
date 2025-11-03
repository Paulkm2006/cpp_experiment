#include "Direction.hpp"

namespace adas
{

	static const Direction directions[4] = {
		{0, 'E'},
		{1, 'S'},
		{2, 'W'},
		{3, 'N'}};

	static const Point points[4] = {
		{1, 0},	 // East
		{0, -1}, // South
		{-1, 0}, // West
		{0, 1}	 // North
	};

	const Direction &Direction::GetDirection(const char heading) noexcept
	{
		for (const auto &dir : directions)
		{
			if (dir.heading == heading)
			{
				return dir;
			}
		}
		return directions[3]; // Default to 'N' if not found
	}

	Direction::Direction(const unsigned index, const char heading) noexcept
		: index(index), heading(heading)
	{
	}

	const Point &Direction::Move(void) const noexcept
	{
		return points[index];
	}

	const Direction &Direction::LeftOne(void) const noexcept
	{
		return directions[(index + 3) % 4];
	}

	const Direction &Direction::RightOne(void) const noexcept
	{
		return directions[(index + 1) % 4];
	}

	char Direction::GetHeading(void) const noexcept
	{
		return heading;
	}
}