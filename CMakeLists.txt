cmake_minimum_required(VERSION 3.5)

project(factorypattern LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(factorypattern main.cpp
)

find_package(Boost 1.84.0)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

include(GNUInstallDirs)
install(TARGETS factorypattern
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
