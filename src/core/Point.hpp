#pragma once

namespace adas
{
	class Point final
	{
	public:
		Point(const int x, const int y) noexcept;
		Point(const Point &rhs) noexcept;

		Point &operator=(const Point &rhs) noexcept;
		Point &operator+=(const Point &rhs) noexcept;
		Point &operator-=(const Point &rhs) noexcept;

		int GetX() const noexcept;
		int GetY() const noexcept;

	private:
		int x;
		int y;
	};
}