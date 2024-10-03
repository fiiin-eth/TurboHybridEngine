cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(TURBOHYBRIDENGINE)

include_directories(
	src
)

add_library(TurboHybridEngine
 src/TurboHybridEngine/dummy.cpp src/TurboHybridEngine/dummy.h
)

add_executable(demo
  src/demo/main.cpp
)

target_link_libraries(demo TurboHybridEngine)