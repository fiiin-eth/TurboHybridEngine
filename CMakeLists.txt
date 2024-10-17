cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(TURBOHYBRIDENGINE)

include_directories(
	src
	contrib/include
)

add_library(TurboHybridEngine
 src/TurboHybridEngine/Core.cpp src/TurboHybridEngine/Core.h
 src/TurboHybridEngine/TurboHybridEngine.h
 src/TurboHybridEngine/Entity.cpp src/TurboHybridEngine/Entity.h
 src/TurboHybridEngine/Component.h src/TurboHybridEngine/Component.cpp
 src/TurboHybridEngine/Transform.h src/TurboHybridEngine/Transform.cpp
)

add_executable(demo
  src/demo/main.cpp
)

target_link_libraries(demo TurboHybridEngine)