cmake_minimum_required(VERSION 3.20)
project(f2l LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(ggclirouter INTERFACE)
target_include_directories(ggclirouter INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/ggclirouter/include
)

add_library(cmd_init
    src/commands/init.cc
)
target_include_directories(cmd_init PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(cmd_init PUBLIC ggclirouter)


add_executable(f2l
    src/f2l.cc
)
target_link_libraries(f2l PRIVATE cmd_init ggclirouter)
