add_library(graphics OBJECT
    graphics.cpp
    graphics.h
)

target_include_directories(graphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
