add_executable(ip_filter
  main.cpp
)

target_link_libraries(ip_filter PRIVATE
  ip_filter_lib
)
