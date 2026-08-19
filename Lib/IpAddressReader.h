/// @file IpAddressReader.h
/// @brief Reader for IP addresses.
/// @author Andrey Stepanov
#pragma once

#include "Types.h"
#include <iosfwd>

/// @brief Reader for IP addresses from a stream.
class IpAddressReader
{
public:
   /// @brief Reads IP addresses from the input stream.
   /// @param in \n[in] Input stream to read from.
   void Read(std::istream& in);

   /// @brief Returns the set of read IP addresses.
   const IpAddressSet& Get() const noexcept
   {
      return m_addrs;
   }

private:
   IpAddressSet m_addrs;
};
