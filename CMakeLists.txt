cmake_minimum_required(VERSION 3.5)


########## Engine built here. Scroll down to find where game is built #####################
project(BSE)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)


# Find SFML libraries dynamically
if(UNIX AND NOT APPLE)
    set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/linux/SFML-2.5.1/lib/cmake/SFML)
endif()

if(WIN32)
    set(SFML_DIR vendor/win32/SFML-2.5.1/lib/cmake/SFML)
endif()


if(WIN32)
    add_custom_target(copy_dlls ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/vendor/win32/SFML-2.5.1/bin ${CMAKE_CURRENT_BINARY_DIR}
)
endif()


find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/BSE/include/core)
include_directories(BSE/include)
#include_directories(${SFML_INCLUDE_DIRS})

# Create shared library target
add_library(BSE SHARED 
    BSE/src/core/Input.cpp 
    BSE/src/core/Window.cpp 
    BSE/src/core/Scene.cpp
)

# Link SFML libraries dynamically
target_link_libraries(BSE sfml-graphics sfml-window sfml-system)

# Set the name of the DLL
set_target_properties(BSE PROPERTIES OUTPUT_NAME BSE)

# Set the prefix and suffix for the DLL name
if(WIN32)
    set_target_properties(BSE PROPERTIES PREFIX "")
    set_target_properties(BSE PROPERTIES SUFFIX ".dll")
endif()

if(UNIX AND NOT APPLE)
    set_target_properties(BSE PROPERTIES PREFIX "lib")
    set_target_properties(BSE PROPERTIES SUFFIX ".so")
endif()


###########GAME BUILT HERE###############



# src headers

include_directories(src/)

# Add executable target
add_executable(Game src/main.cpp src/Player.cpp src/Football.cpp src/Spawner.cpp)


# Link SFML libraries to executable
target_link_libraries(Game BSE)

if(UNIX AND NOT APPLE)
	target_link_libraries(Game stdc++)
endif()







