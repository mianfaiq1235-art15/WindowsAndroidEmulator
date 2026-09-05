cmake_minimum_required(VERSION 3.20)
project(WindowsAndroidEmulator CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source directories
add_subdirectory(src/core)
add_subdirectory(src/ui)
add_subdirectory(src/system)
add_subdirectory(src/graphics)
add_subdirectory(src/utils)

# Main executable
add_executable(WindowsAndroidEmulator 
    src/main.cpp
    $<TARGET_OBJECTS:core>
    $<TARGET_OBJECTS:ui>
    $<TARGET_OBJECTS:system>
    $<TARGET_OBJECTS:graphics>
    $<TARGET_OBJECTS:utils>
)

# Link libraries
target_link_libraries(WindowsAndroidEmulator 
    d3d11.lib
    dxgi.lib
)

# Set output directory
set_target_properties(WindowsAndroidEmulator PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Compiler flags
if(MSVC)
    target_compile_options(WindowsAndroidEmulator PRIVATE /W4 /O2)
else()
    target_compile_options(WindowsAndroidEmulator PRIVATE -Wall -O2)
endif()
