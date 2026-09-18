add_library(LivingRoomLib Album.cpp LivingRoom.cpp)
include(FetchContent)

FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                    GIT_TAG 1.14.2)
FetchContent_MakeAvailable(cpr)
target_link_libraries(LivingRoomLib PUBLIC cpr::cpr)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)
target_link_libraries(LivingRoomLib PUBLIC nlohmann_json::nlohmann_json)

target_include_directories(LivingRoomLib PUBLIC ../include/)