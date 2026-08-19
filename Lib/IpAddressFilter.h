/// @file IpAddressFilter.h
/// @brief Filter for IP addresses.
/// @author Andrey Stepanov

#include "Types.h"
#include <functional>

/// @brief Type of filter for IP addresses.
using IpAddressFilter = std::function<bool(const IpAddress&)>;

/// @brief Filters IP addresses with a given filter.
/// @param ipAddrs \n[in] Set of IP addresses to filter.
/// @param filter \n[in] Filter to apply.
/// @return Set of filtered IP addresses.
IpAddressSet Filter(const IpAddressSet& ipAddrs, const IpAddressFilter& filter);
