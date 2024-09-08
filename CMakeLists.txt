cmake_minimum_required(VERSION 3.28)

set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE STRING INTERNAL FORCE)

project(Visualizer VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
enable_language(C CXX)

add_subdirectory(FMOD)

set(SOURCES)
set(HEADERS)

list(APPEND SOURCES main.cpp AudioEngine.cpp)
list(APPEND HEADERS AudioEngine.hpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} fmod_core fmod_studio)

add_custom_target(CopyDependencies 
    COMMAND ${CMAKE_COMMAND} 
    -E make_directory $<TARGET_FILE_DIR:${PROJECT_NAME}> 
    COMMAND ${CMAKE_COMMAND} 
    -E copy_if_different $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}>
    COMMAND_EXPAND_LISTS
)

add_dependencies(${PROJECT_NAME} CopyDependencies)
