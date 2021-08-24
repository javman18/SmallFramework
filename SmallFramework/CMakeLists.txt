cmake_minimum_required(VERSION 3.0.0)
set(cmake_cxx_standard 17)
set(cmake_cxx_standard_required on)

project(SmallFramework)

include_directories("include")
include_directories("../ExternalLibs/glew-2.1.0/include")
include_directories("../ExternalLibs/glfw-3.3.4.bin.WIN64/include")
include_directories("../ExternalLibs/glm/glm")
include_directories("../ExternalLibs/std_image/include")

add_executable(SmallFramework "src/Game.cpp"
                              "src/GameState.cpp"
                              "src/GameStateManager.cpp"
                              "src/Model.cpp"
                              "src/Object.cpp"
                              "src/Plane.cpp"
                              "SmallFramework/src/Platform.cpp"
                              "src/Shader.cpp"
                              "src/Texture.cpp")