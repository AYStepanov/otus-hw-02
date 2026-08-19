/// @file main.cpp
/// @brief Entry point of the application.
/// @author Andrey Stepanov
#include "Lib/IpAddressReader.h"
#include "Lib/IpAddressFilter.h"
#include <iostream>
#include <algorithm>

int main(int, char **)
{
	const auto printer = [](const IpAddress& addr)
	{
		std::cout << addr.to_string() << '\n';
	};

	IpAddressReader reader;
	reader.Read(std::cin);

	// 1. All IP addresses.
	const auto& ipAddrs = reader.Get();
	std::for_each(ipAddrs.crbegin(), ipAddrs.crend(), printer);

	// 2. IP addresses starting with 1.
	const auto ipAddrs1 = Filter(ipAddrs, [](const IpAddress& addr)
		{
			return (addr.to_uint() & 0xFF000000) == 0x01000000;
		});
	std::for_each(ipAddrs1.crbegin(), ipAddrs1.crend(), printer);

	// 3. IP addresses starting with 46 and 70.
	const auto ipAddrs4670 = Filter(ipAddrs, [](const IpAddress& addr)
		{
			return (addr.to_uint() & 0xFFFF0000) == 0x2E460000;
		});
	std::for_each(ipAddrs4670.crbegin(), ipAddrs4670.crend(), printer);

	// 4. IP addresses has with any 46.
	const auto ipAddrs46 = Filter(ipAddrs, [](const IpAddress& addr)
		{
			const auto uintIP = addr.to_uint();
			return ((uintIP & 0xFF000000) == 0x2E000000)
				|| ((uintIP & 0x00FF0000) == 0x002E0000)
				|| ((uintIP & 0x0000FF00) == 0x00002E00)
				|| ((uintIP & 0x000000FF) == 0x0000002E);
		});
	std::for_each(ipAddrs46.crbegin(), ipAddrs46.crend(), printer);

	return 0;
}
