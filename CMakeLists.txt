cmake_minimum_required(VERSION 3.16)
project(raycaster)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Og -Wall -Wextra -include cstddef -fdiagnostics-color=always")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_RELEASE} -O3 -Wall -Wextra -include cstddef -fdiagnostics-color=always")

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -municode -Wl,-subsystem,windows")
endif()

add_executable(raycaster 
    render.cpp
    main.cpp)
target_include_directories(raycaster PRIVATE ${PROJECT_SOURCE_DIR}/src "C:\\Users\\satojam\\dev\\lib\\sdl-2.29.3\\x86_64-w64-mingw32\\include")


target_link_directories(raycaster PRIVATE "C:\\Users\\satojam\\dev\\lib\\sdl-2.29.3")
target_link_libraries(raycaster PRIVATE sdl2)
install(TARGETS raycaster DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})


