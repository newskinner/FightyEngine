cmake_minimum_required(VERSION 4.0)
project(
    FightyEngine
    VERSION 0.0.1
    LANGUAGES CXX
)

file(GLOB_RECURSE graphics_sources      src/graphics/*.cpp src/graphics/*.h)
file(GLOB_RECURSE core_sources          src/miacra/*.cpp src/miacra/*.h)
set(main                                src/main.cpp)

add_executable(engine ${graphics_sources} ${core_sources})
target_compile_options(engine PUBLIC -I/usr/include/freetype2 -I/usr/include/glm -lglfw -lGL -lfreetype -ldl -pthread)
target_include_directories(engine PUBLIC src)

find_package(OpenGL REQUIRED)
target_link_libraries(engine PUBLIC
    ${OPENGL_LIBRARY}
)