cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(TURBOHYBRIDENGINE)

include_directories(
	src
	contrib/include
	contrib/cl-windows-x86_64/include
)

link_directories(
	contrib/cl-windows-x86_64/lib
)

add_library(rend
	src/rend/Texture.cpp src/rend/Texture.h
	src/rend/Mesh.cpp src/rend/Mesh.h
	src/rend/ShaderProgram.cpp src/rend/ShaderProgram.h
	src/rend/Model.h
	src/rend/Rend.h
)

target_link_libraries(rend SDL2 glew32 OpenGL32)

add_library(TurboHybridEngine
 src/TurboHybridEngine/Core.cpp src/TurboHybridEngine/Core.h
 src/TurboHybridEngine/TurboHybridEngine.h
 src/TurboHybridEngine/Entity.cpp src/TurboHybridEngine/Entity.h
 src/TurboHybridEngine/Component.h src/TurboHybridEngine/Component.cpp
 src/TurboHybridEngine/Transform.h src/TurboHybridEngine/Transform.cpp
 src/TurboHybridEngine/Window.h src/TurboHybridEngine/Window.cpp
 src/TurboHybridEngine/TriangleRenderer.h src/TurboHybridEngine/TriangleRenderer.cpp
 src/TurboHybridEngine/Resource.h src/TurboHybridEngine/Resource.cpp
 src/TurboHybridEngine/Input.h src/TurboHybridEngine/Input.cpp
 src/TurboHybridEngine/Keyboard.h src/TurboHybridEngine/Keyboard.cpp
 src/TurboHybridEngine/Audio.h src/TurboHybridEngine/Audio.cpp
 src/TurboHybridEngine/AudioSource.h src/TurboHybridEngine/AudioSource.cpp
 src/TurboHybridEngine/Sound.h src/TurboHybridEngine/Sound.cpp
 src/TurboHybridEngine/Texture.h
 src/TurboHybridEngine/Resources.h
 src/TurboHybridEngine/Model.h 
)

target_link_libraries(TurboHybridEngine rend openal32)

add_executable(demo
  src/demo/main.cpp
)

target_link_libraries(demo TurboHybridEngine)