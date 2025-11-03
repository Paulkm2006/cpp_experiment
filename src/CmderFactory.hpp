#pragma once
#include <functional>
#include <list>
#include <unordered_map>

#include "Command.hpp"

namespace adas
{

	using Cmder = std::function<ActionGroup(PoseHandler &)>;
	using CmderList = std::list<Cmder>;

	class CmderFactory
	{
	public:
		CmderFactory(void) = default;
		~CmderFactory(void) = default;

		CmderFactory(const CmderFactory &) = delete;
		CmderFactory &operator=(const CmderFactory &) = delete;

		CmderList GetCmders(const std::string &commands) const noexcept;

	private:
		const std::unordered_map<char, Cmder> commandMap{
			{'M', MoveCmd()},
			{'L', LeftCmd()},
			{'R', RightCmd()},
			{'F', FastCmd()},
			{'B', BackCmd()}};
	};

}