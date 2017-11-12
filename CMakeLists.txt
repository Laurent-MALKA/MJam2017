cmake_minimum_required(VERSION 3.8)
project(Mjam2017)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${project_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 11)




set(SOURCE_FILES src/main.cpp src/Inputs.cpp src/Inputs.hpp src/Display.cpp src/Display.hpp src/Jeu.cpp src/Jeu.hpp src/Moteur.cpp src/Moteur.hpp src/Perso.cpp src/Perso.hpp src/Body.cpp src/Body.hpp src/Grappin.cpp src/Grappin.hpp src/Touches.cpp src/Touches.hpp src/Bonus.cpp src/Bonus.hpp src/Cola.cpp src/Cola.hpp src/Teleporteur.cpp src/Teleporteur.hpp src/Map.cpp src/Map.hpp src/Obstacle.cpp src/Obstacle.hpp src/Animation.cpp src/Animation.hpp src/Image.cpp src/Image.hpp src/BeerBar.cpp src/BeerBar.hpp)

set(CMAKE_CXX_FLAGS "-lSDL2 -lSDL2_ttf -lSDL2_image")

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../exe )

add_executable(Mjam2017 ${SOURCE_FILES})
target_link_libraries(Mjam2017 ${SDL2_LIBRARY})