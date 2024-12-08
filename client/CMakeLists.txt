# CMake 최소 요구 버전 설정
cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름 및 C++ 표준 설정
project(GAB)
set(CMAKE_CXX_STANDARD 17)

# Boost 경로를 추가합니다 (Homebrew 설치 경로).
set(BOOST_ROOT "/opt/homebrew/opt/boost")
set(CMAKE_PREFIX_PATH ${BOOST_ROOT})

# Boost 라이브러리를 찾습니다.
find_package(
    Boost
    REQUIRED
    COMPONENTS
    system
    thread
)

# Boost가 없으면 에러 처리
if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find Boost libraries.")
endif()

# 🔥 SDL 라이브러리 경로 설정 (사용자가 설치한 위치에 맞게 변경)
set(SDL2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/lib/SDL/install/include)
set(SDL2_LIB_DIR ${CMAKE_SOURCE_DIR}/lib/SDL/install/lib)


# 🔥 헤더 파일 경로 추가 (include 디렉토리를 포함)
include_directories(
    ${SDL2_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/include
)

# 🔥 링크할 라이브러리 경로 추가
link_directories(${SDL2_LIB_DIR})

# 🔥 소스 파일 및 헤더 파일 자동 추가 (src 디렉토리 내 모든 *.cpp 파일을 추가)
file(
    GLOB_RECURSE
    SRC_FILES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

# 🔥 실행 파일 생성 (소스 파일 추가)
add_executable(GAB ${SRC_FILES})

# 🔥 링크할 라이브러리 추가 (SDL2 라이브러리 연결)
target_link_libraries(
    GAB
    SDL2
    Boost::system
    Boost::thread
)
