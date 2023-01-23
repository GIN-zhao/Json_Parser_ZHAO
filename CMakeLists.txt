cmake_minimum_required (VERSION 2.8)

project (MYJSON_PROJECT)

include_directories(./include)

set (SRC_LIST ./main.cpp)

add_executable (main ${SRC_LIST})

set (EXECUTABLE_OUTPUT_PATH &{PROJECT_SOURCE_DIR}/bin)
