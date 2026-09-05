add_library(core OBJECT
    emulator.cpp
    emulator.h
)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
