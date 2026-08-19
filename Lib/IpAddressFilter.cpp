/// @file IpAddressFilter.cpp
/// @brief Filter for IP addresses.
/// @author Andrey Stepanov

#include "IpAddressFilter.h"

IpAddressSet Filter(const IpAddressSet& ipAddrs, const IpAddressFilter& filter)
{
    IpAddressSet filteredIpAddrs;
    for (const auto& ip : ipAddrs)
    {
        if (filter(ip))
        {
            filteredIpAddrs.insert(ip);
        }
    }
    return filteredIpAddrs;
}
