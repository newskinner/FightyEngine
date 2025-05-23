cmake_minimum_required(VERSION 4.0)
project(
    FightyEngine
    VERSION 0.0.1
    LANGUAGES C CXX
)

file(GLOB_RECURSE graphics_sources      FightyEngine/graphics/*.cpp FightyEngine/graphics/*.h)
file(GLOB_RECURSE core_sources          FightyEngine/miacra/*.cpp FightyEngine/miacra/*.h)
set(main                                FightyEngine/main.cpp)

add_library(inih_c STATIC               include/inih/ini.c)
add_executable(engine ${graphics_sources} ${core_sources} ${main} ${inih_sources})
set_target_properties(engine PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
target_compile_options(engine PUBLIC -I/usr/include/freetype2 -I/usr/include/glm -lglfw -lGL -lfreetype -ldl -pthread)
target_include_directories(inih_c PUBLIC include/inih)
target_include_directories(engine PUBLIC
    FightyEngine
    include/inih
)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
target_link_libraries(engine PUBLIC
    ${OPENGL_LIBRARY}
    glfw
    GL
    freetype
    dl
    pthread
    inih_c
)

add_custom_target(run
    COMMAND engine
    DEPENDS engine
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

add_custom_target(cleanup
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_BINARY_DIR}/build/engine
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_BINARY_DIR}/CMakeCache.txt
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_BINARY_DIR}/Makefile
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_BINARY_DIR}/cmake_install.cmake
    COMMENT "Cleaning up all build files"
)
