#include "CmderFactory.hpp"
#include <algorithm>

namespace adas
{

	CmderList adas::CmderFactory::GetCmders(const std::string &commands) const noexcept
	{
		CmderList cmders;
		for (const auto cmd : ParseCommands(commands))
		{
			const auto it = commandMap.find(cmd);
			if (it != commandMap.end())
			{
				cmders.push_back(it->second);
			}
		}
		return cmders;
	}

	std::string CmderFactory::ParseCommands(const std::string_view commands) const noexcept
	{
		std::string result(commands);
		ReplaceAll(result, "TR", "Z");
		return result;
	}

	void CmderFactory::ReplaceAll(std::string &str, std::string_view what, std::string_view with) const noexcept
	{
		size_t pos = 0;
		while ((pos = str.find(what, pos)) != std::string::npos)
		{
			str.replace(pos, what.length(), with);
			pos += with.length();
		}
	}
}