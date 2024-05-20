cmake_minimum_required(VERSION 3.8)

project(VTKWriter)

set(TARGET_NAME VTKWriter)

SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 ")

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(${TARGET_NAME} ${SRC_FILES})

# 确保项目使用 C++17
target_compile_features(${TARGET_NAME} PUBLIC cxx_std_17)

# bin 路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)