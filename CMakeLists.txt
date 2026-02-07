cmake_minimum_required(VERSION 3.20)

project(Turn_Based_Console_RPG LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Turn_Based_Console_RPG
    src/main.cpp
    src/core/GameManager.cpp
    src/entity/Enemy.cpp
    src/states/GameOverState.cpp
    src/states/GameWinState.cpp
)

target_include_directories(Turn_Based_Console_RPG PRIVATE src)
