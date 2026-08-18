add_executable(helloworld_cli
  main.cpp
)

target_link_libraries(helloworld_cli PRIVATE
  helloworld
)
