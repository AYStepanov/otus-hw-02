find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(helloworld_test
  test_version.cpp
)

target_compile_definitions(helloworld_test PRIVATE
  BOOST_TEST_DYN_LINK
)

target_link_libraries(helloworld_test PRIVATE
  Boost::unit_test_framework
  helloworld
)

add_test(NAME helloworld_test COMMAND helloworld_test)
