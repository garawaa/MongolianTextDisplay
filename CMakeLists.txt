cmake_minimum_required(VERSION 3.20)

project(MongolianTextDisplay)

# Define the library
add_library(MongolianTextDisplay
    bitmaps.cpp
    bitmaps.h
)

# Set include directory for the library
target_include_directories(MongolianTextDisplay PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Optionally, link dependencies (if needed for future versions)
# For example: target_link_libraries(MongolianTextDisplay AdafruitGFX)

# Arduino-specific settings can go here if you're using Arduino-CMake
# For example:
# set(ARDUINO_BOARD uno)
# generate_arduino_firmware(MongolianTextDemo
#     SRCS examples/BasicDemo/BasicDemo.ino
#     BOARD uno
#     LIBS MongolianTextDisplay
# )
