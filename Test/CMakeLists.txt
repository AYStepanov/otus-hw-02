find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(ip_filter_test
  IpFilterTests.cpp
)

target_compile_definitions(ip_filter_test PRIVATE
  BOOST_TEST_DYN_LINK
)

target_link_libraries(ip_filter_test PRIVATE
  Boost::unit_test_framework
  ip_filter_lib
)

add_test(NAME ip_filter_test COMMAND ip_filter_test)
