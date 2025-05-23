cmake_minimum_required(VERSION 4.0)
project(
    FightyEngine
    VERSION 0.0.1
    LANGUAGES CXX
)

file(GLOB_RECURSE graphics_sources      src/graphics/*.cpp src/graphics/*.h)
file(GLOB_RECURSE core_sources          src/miacra/*.cpp src/miacra/*.h)
set(main                                src/main.cpp)

add_executable(engine ${graphics_sources} ${core_sources} ${main})
set_target_properties(engine PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
target_compile_options(engine PUBLIC -I/usr/include/freetype2 -I/usr/include/glm -lglfw -lGL -lfreetype -ldl -pthread)
target_include_directories(engine PUBLIC src)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
target_link_libraries(engine PUBLIC
    ${OPENGL_LIBRARY}
    glfw
)

add_custom_target(run
    COMMAND engine
    DEPENDS engine
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)