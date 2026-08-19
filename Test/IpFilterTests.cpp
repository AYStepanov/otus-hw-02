/// @file IpFilterTests.cpp
/// @brief Unit tests.
/// @author Andrey Stepanov
#define BOOST_TEST_MODULE IpFilterTests

#include "Lib/IpAddressReader.h"
#include "Lib/IpAddressFilter.h"
#include <boost/test/unit_test.hpp>
#include <sstream>
#include <string>

namespace ip = boost::asio::ip;

BOOST_AUTO_TEST_SUITE(IpFilterTests)

BOOST_AUTO_TEST_CASE(empty_input)
{
   const std::string empty;
	std::istringstream iss(empty);

	IpAddressReader reader;
	reader.Read(iss);
	BOOST_CHECK(reader.Get().empty());
}

BOOST_AUTO_TEST_CASE(single_ip_address)
{
   const std::string input = "192.168.1.1";
	std::istringstream iss(input);

	IpAddressReader reader;
	reader.Read(iss);
	BOOST_CHECK(reader.Get().size() == 1);
	BOOST_CHECK(reader.Get().contains(ip::make_address_v4(input)));
}

BOOST_AUTO_TEST_CASE(single_ip_address_with_extra_params)
{
   const std::string input = "95.42.141.179\t2\t0";
	std::istringstream iss(input);

	IpAddressReader reader;
	reader.Read(iss);
	BOOST_CHECK(reader.Get().size() == 1);
	BOOST_CHECK(reader.Get().contains(ip::make_address_v4("95.42.141.179")));
}

BOOST_AUTO_TEST_CASE(multiple_ip_addresses)
{
   const std::string input =
	   "95.42.141.179\n"
		"192.168.1.1\n"
		"103.240.127.33\t2\t0";
	std::istringstream iss(input);

	IpAddressReader reader;
	reader.Read(iss);
	BOOST_CHECK(reader.Get().size() == 3);
	BOOST_CHECK(reader.Get().contains(ip::make_address_v4("95.42.141.179")));
	BOOST_CHECK(reader.Get().contains(ip::make_address_v4("192.168.1.1")));
	BOOST_CHECK(reader.Get().contains(ip::make_address_v4("103.240.127.33")));
}

BOOST_AUTO_TEST_CASE(filter_ip_addresses)
{
   const std::string input =
	   "95.42.141.179\n"
		"192.168.1.1\n"
		"103.240.127.33\t2\t0";
	std::istringstream iss(input);

	IpAddressReader reader;
	reader.Read(iss);

	const auto ipAddrs = Filter(reader.Get(), [](const IpAddress& addr) {
		return addr.to_string().starts_with("103.240");
	});
	BOOST_CHECK(ipAddrs.size() == 1);
	BOOST_CHECK(ipAddrs.contains(ip::make_address_v4("103.240.127.33")));
}

BOOST_AUTO_TEST_SUITE_END()
