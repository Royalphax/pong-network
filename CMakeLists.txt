cmake_minimum_required(VERSION 3.6)
project(pong-network)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "-static-libgcc -static-libstdc++")
#set(CMAKE_STATIC_LINKER_FLAGS "-lwsock32 -lws2_32")
set(SOURCE_FILES src/client/Main.cpp src/server/Main.cpp)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
#set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/msgpack-cxx-4.1.1)

# JSON lib
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)
include_directories(nlohmann_json/include)

# SockCPP
#set(SOCKPP_BUILD_STATIC OFF)
#set(SOCKPP_BUILD_OBJS OFF)
add_subdirectory(sockpp)
include_directories(sockpp/include)

# Global include directories shared by library, server, and client
include_directories(src/common/include)
add_library(common src/common/lib.cpp)
target_link_libraries(common PUBLIC nlohmann_json::nlohmann_json PUBLIC sockpp-static)

# Make the server
add_executable(server src/server/Main.cpp src/server/GameManager.cpp src/server/SocketServer.cpp)
target_include_directories(server PUBLIC src/server/include) # add the server's specific include file
target_link_libraries(server PUBLIC nlohmann_json::nlohmann_json PUBLIC sockpp-static PUBLIC ws2_32) # link the server with the shared library

# Make the client
set(SDL2_PATH "src\\client\\SDL2")
find_package(SDL2 REQUIRED)
set(SDL2_TTF_PATH "src\\client\\SDL2")
find_package(SDL2_ttf REQUIRED)
include_directories(src/client/SDL2/include/SDL2)
add_executable(client src/client/Main.cpp src/client/GUI.cpp src/client/SocketManager.cpp)
target_include_directories(client PUBLIC src/client/include PUBLIC ${SDL2_INCLUDE_DIR}) # add the client's specific include file
target_link_libraries(client PUBLIC common PUBLIC nlohmann_json::nlohmann_json PUBLIC sockpp-static PUBLIC mingw32 PUBLIC ws2_32 PUBLIC ${SDL2_LIBRARY} PUBLIC ${SDL2_TTF_LIBRARY}) # link client with the shared library