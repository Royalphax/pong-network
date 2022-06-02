cmake_minimum_required(VERSION 3.6)
project(pong-network)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
set(SOURCE_FILES src/client/main.cpp src/server/main.cpp)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

# Global include directories shared by library, server, and client
include_directories(src/common/include)

# Make the shared library
add_library(client_server_lib src/common/lib.cpp)

# Make the server
add_executable(server src/server/main.cpp)
target_include_directories(server PUBLIC src/server/include) # add the server's specific include file
target_link_libraries(server client_server_lib) # link the server with the shared library

# Make the client
set(SDL2_PATH "src\\client\\SDL2")
find_package(SDL2 REQUIRED)
add_executable(client src/client/main.cpp)
target_include_directories(client PUBLIC ${SDL2_INCLUDE_DIR}) # add the client's specific include file
target_link_libraries(client client_server_lib mingw32 ${SDL2_LIBRARY}) # link client with the shared library