cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(TURBOHYBRIDENGINE)

include_directories(
	src
	contrib/include
)

link_directories(
	contrib/lib
)

add_library(TurboHybridEngine
 src/TurboHybridEngine/Core.cpp src/TurboHybridEngine/Core.h
 src/TurboHybridEngine/TurboHybridEngine.h
 src/TurboHybridEngine/Entity.cpp src/TurboHybridEngine/Entity.h
 src/TurboHybridEngine/Component.h src/TurboHybridEngine/Component.cpp
 src/TurboHybridEngine/Transform.h src/TurboHybridEngine/Transform.cpp
 src/TurboHybridEngine/ShaderProgram.h src/TurboHybridEngine/ShaderProgram.cpp
 src/TurboHybridEngine/Texture.h src/TurboHybridEngine/Texture.cpp
 src/TurboHybridEngine/Model.h
 src/TurboHybridEngine/Mesh.h src/TurboHybridEngine/Mesh.cpp
)

target_link_libraries(TurboHybridEngine SDL2 glew32 OpenGL32)

add_executable(demo
  src/demo/main.cpp
)

target_link_libraries(demo TurboHybridEngine)