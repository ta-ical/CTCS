cmake_minimum_required (VERSION 2.8.11)
project ("Sempack" LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# For pthread
find_package (Threads)

add_executable(sem src/sem_main.cpp src/sem.cpp)