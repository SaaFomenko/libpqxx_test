cmake_minimum_required(VERSION 3.30)

set( CMAKE_CXX_COMPILER "C:\\msys64\\ucrt64\\bin\\g++.exe" )

set( CMAKE_C_COMPILER "C:\\msys64\\ucrt64\\bin\\gcc.exe" )

project(libpqxx_test)

set(PostgeSQL_ADDITIONAL_VERSIONS "16")

add_executable(libpqxx_test main.cpp)

add_subdirectory("C:\\projects\\c++\\sql\\nlogy\\libpqxx-7.9.2" libpqxx-build) # Укажите путь к libpq++

target_compile_features(libpqxx_test PRIVATE cxx_std_17) # Включите C++17

target_link_libraries(libpqxx_test pqxx)