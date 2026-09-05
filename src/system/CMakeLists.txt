add_library(system OBJECT
    android_system.cpp
    android_system.h
)

target_include_directories(system PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
