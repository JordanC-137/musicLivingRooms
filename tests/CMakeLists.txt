enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(firstTest Album_test.cpp)
target_link_libraries(firstTest PRIVATE gtest_main)
target_link_libraries(firstTest PRIVATE LivingRoomLib)