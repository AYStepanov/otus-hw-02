add_library(helloworld
  lib.cpp
  lib.h
)

configure_file(version.h.in version.h)
