cmake_minimum_required(VERSION 3.0.0)
set(cmake_cxx_standard 17)
set(cmake_cxx_standard_required on)

project(SmallFramework)

include_directories("include")
include_directories("../ExternalLibs/glew-2.1.0/include")
include_directories("../ExternalLibs/glfw-3.3.4.bin.WIN64/include/GLFW")
include_directories("../ExternalLibs/glm/glm")
include_directories("../ExternalLibs/std_image/include")

add_executable(SmallFramework 
"include/Game.h"
                              "include/GameState.h"
                              "include/GameStateManager.h"
                              "include/Model.h"
                              "include/Object.h"
                              "include/Plane.h"
                              "include/Platform.h"
                              "include/Shader.h"
			      "include/Transform.h"
			      "include/Box.h"
                              "include/Texture.h"

			      "src/Game.cpp"
                              "src/GameState.cpp"
                              "src/GameStateManager.cpp"
                              "src/SmallFramework.cpp"
                              "src/Model.cpp"
                              "src/Object.cpp"
                              "src/Plane.cpp"
                              "src/Platform.cpp"
                              "src/Shader.cpp"
			      "src/Transform.cpp"
			      "src/Box.cpp"
                              "src/Texture.cpp")

target_link_libraries(SmallFramework "../../ExternalLibs/glew-2.1.0/lib/Release/x64/glew32"
                                     "../../ExternalLibs/glfw-3.3.4.bin.WIN64/lib-vc2019/glfw3"
                                     "Opengl32")