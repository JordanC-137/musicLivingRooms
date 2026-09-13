add_library(LivingRoomLib Album.cpp LivingRoom.cpp)
include(FetchContent)

FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                    GIT_TAG 1.14.2)
FetchContent_MakeAvailable(cpr)
target_link_libraries(LivingRoomLib PUBLIC cpr::cpr)
target_include_directories(LivingRoomLib PUBLIC ../include/)