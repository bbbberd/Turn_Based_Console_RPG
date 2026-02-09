cmake_minimum_required(VERSION 3.20)
# Menentukan versi minimum CMake yang boleh dipakai untuk build project ini
# Jika user pakai CMake versi < 3.20 ? build akan ditolak
# Tujuannya:
# - Menghindari fitur CMake lama
# - Menjamin perilaku konsisten


project(Turn_Based_Console_RPG LANGUAGES CXX)
# Mendefinisikan nama project dan compiler

set(CMAKE_CXX_STANDARD 17)# Menentukan standar C++ yang dipakai adalah C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)# Kalau compiler tidak mendukung ? build gagal
set(CMAKE_CXX_EXTENSIONS OFF)# Mematikan extension khusus compiler (misal GNU extensions)

add_executable(Turn_Based_Console_RPG
# Membuat target executable (program .exe)
# Nama output program = Turn_Based_Console_RPG

    src/main.cpp# Entry point program (main)
    src/core/GameManager.cpp# Implementasi singleton + game loop
    src/entity/Enemy.cpp# Implementasi logika musuh
    src/states/GameOverState.cpp# State game over
    src/states/GameWinState.cpp# State menang
)
# Semua file .cpp di atas akan di-compile dan di-link jadi 1 executable

target_include_directories(Turn_Based_Console_RPG PRIVATE src)
# Menambahkan folder "src" ke include path compiler
# PRIVATE artinya hanya target ini yang pakai include path tersebut
