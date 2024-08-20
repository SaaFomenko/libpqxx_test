cmake_minimum_required(VERSION 3.30)

set( CMAKE_CXX_COMPILER "c:\\mingw\\bin\\g++.exe" )

set( CMAKE_C_COMPILER "c:\\mingw\\bin\\gcc.exe" )

project(libpqxx_mytest)

add_executable($(PROJECT_NAME) main.cpp)

add_subdirectory("C:\\projects\\c++\\libpqxx-7.9.2" libpqxx-build) # Укажите путь к libpq++

target_compile_features($(PROJECT_NAME) PRIVATE cxx_std_17) # Включите C++17

target_link_libraries($(PROJECT_NAME) pqxx)