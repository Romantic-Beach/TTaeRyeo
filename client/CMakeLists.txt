cmake_minimum_required(VERSION 3.10)
project(GAB)

set(CMAKE_CXX_STANDARD 17)

# SDL3 라이브러리 경로
set(SDL2_INCLUDE_DIR lib/SDL/install/include)
set(SDL2_LIB_DIR lib/SDL/install/lib)

# 헤더 파일 경로
include_directories(
    ${SDL2_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/include
)

# 링크할 라이브러리
link_directories(${SDL2_LIB_DIR})

add_executable(
    GAB
    src/main.cpp
    src/Game.cpp
    src/JoystickInput.cpp
    src/KeyboardInput.cpp
    src/Map.cpp
    src/Item.cpp
    src/Physics.cpp
    src/Player.cpp
)

target_link_libraries(
    GAB
    SDL2
)
