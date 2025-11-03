#pragma once
#include <functional>
#include <list>
#include <unordered_map>

#include "cmder/Command.hpp"

namespace adas
{

	using Cmder = std::function<ActionGroup(PoseHandler &, const CmderOrchestrator &)>;
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
		std::string ParseCommands(const std::string_view commands) const noexcept;
		void ReplaceAll(std::string &str, std::string_view what, std::string_view with) const noexcept;

		const std::unordered_map<char, Cmder> commandMap{
			{'M', MoveCmd()},
			{'L', LeftCmd()},
			{'R', RightCmd()},
			{'F', FastCmd()},
			{'B', BackCmd()},
			{'Z', TurnRoundCmd()}};
	};

}