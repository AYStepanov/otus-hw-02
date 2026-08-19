/// @file Types.h
/// @brief Common types definitions.
/// @author Andrey Stepanov
#pragma once

#include <boost/asio/ip/address.hpp>
#include <set>

/// @brief IPv4 address type.
using IpAddress = boost::asio::ip::address_v4;

/// @brief Set of IPv4 addresses.
using IpAddressSet = std::multiset<IpAddress>;