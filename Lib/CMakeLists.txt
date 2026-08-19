find_package(Boost REQUIRED COMPONENTS headers)

add_library(ip_filter_lib
  IpAddressFilter.cpp
  IpAddressFilter.h
  IpAddressReader.cpp
  IpAddressReader.h
  Types.h
)

target_link_libraries(ip_filter_lib PUBLIC
  Boost::headers
)

configure_file(version.h.in version.h)
