#Minimum version to allow FetchContent
cmake_minimum_required(VERSION 3.14)

project(LivingRooms)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

add_subdirectory(src/)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC LivingRoomLib)

enable_testing()
include(FetchContent)
FetchContent_Declare(
    googletest
    //Update commit URL
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(firstTest tests/Album_test.cpp)

target_link_libraries(firstTest PUBLIC gtest_main)
target_link_libraries(firstTest PUBLIC LivingRoomLib)
