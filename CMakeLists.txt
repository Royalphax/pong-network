cmake_minimum_required(VERSION 3.6)
project(pong-network)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(SOURCE_FILES src/client/main.cpp src/server/main.cpp)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
#set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/msgpack-cxx-4.1.1)

# JSON lib
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)
include_directories(nlohmann_json/include)

# Global include directories shared by library, server, and client
include_directories(src/common/include)
add_library(common src/common/lib.cpp)
target_link_libraries(common PUBLIC nlohmann_json::nlohmann_json)

# Make the server
add_executable(server src/server/main.cpp src/server/GameManager.cpp src/server/GameManager.h src/server/Utils.cpp)
target_include_directories(server PUBLIC src/server/include) # add the server's specific include file
target_link_libraries(server PUBLIC common PUBLIC nlohmann_json::nlohmann_json) # link the server with the shared library

# Make the client
set(SDL2_PATH "src\\client\\SDL2")
find_package(SDL2 REQUIRED)
set(SDL2_TTF_PATH "src\\client\\SDL2")
find_package(SDL2_ttf REQUIRED)
set(SDL2_IMAGE_PATH "src\\client\\SDL2")
find_package(SDL2_image REQUIRED)
include_directories(src/client/SDL2/include/SDL2)
add_executable(client src/client/main.cpp src/client/GUI.h src/client/GUI.cpp src/client/GUIState.h src/client/SocketManager.h src/client/SocketManager.cpp)
target_include_directories(client PUBLIC ${SDL2_INCLUDE_DIR}) # add the client's specific include file
target_link_libraries(client PUBLIC common PUBLIC nlohmann_json::nlohmann_json mingw32 ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY}) # link client with the shared library