#include "CmderFactory.hpp"
#include <algorithm>

namespace adas
{
	CmderList adas::CmderFactory::GetCmders(const std::string &commands) const noexcept
	{
		CmderList cmders;
		std::for_each(commands.begin(), commands.end(),
					  [this, &cmders](const char command) noexcept
					  {
						  const auto it = this->commandMap.find(command);
						  if (it != this->commandMap.end())
						  {
							  cmders.push_back(it->second);
						  }
					  });
		return cmders;
	}
}