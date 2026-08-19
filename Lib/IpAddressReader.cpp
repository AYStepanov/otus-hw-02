/// @file IpAddressReader.cpp
/// @brief Reader for IP addresses.
/// @author Andrey Stepanov

#include "IpAddressReader.h"
#include <sstream>
#include <string>

namespace
{

/// @brief Returns the first token from the line splited by a delimiter.
/// @param line \n[in] The line to parse.
/// @param delimiter \n[in] The token delimiter.
/// @return The first token from the line.
std::string getFirstToken(const std::string &line, char delimiter)
{
   std::istringstream iss(line);

   std::string token;
   std::getline(iss, token, delimiter);

   return token;
}

} // unnamed namespace

void IpAddressReader::Read(std::istream& in)
{
   for(std::string line; std::getline(in, line);)
   {
      const auto ip = getFirstToken(line, '\t');
      m_addrs.insert(boost::asio::ip::make_address_v4(ip));
   }
}