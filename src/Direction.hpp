#pragma once

#include "Point.hpp"

namespace adas
{
	class Direction final
	{
	public:
		Direction(const unsigned index, const char heading) noexcept;
		static const Direction &GetDirection(const char heading) noexcept;

		const Point &Move(void) const noexcept;
		const Direction &LeftOne(void) const noexcept;
		const Direction &RightOne(void) const noexcept;

		char GetHeading(void) const noexcept;

	private:
		unsigned index;
		char heading;
	};
} // namespace adas