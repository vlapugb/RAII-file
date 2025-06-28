cmake_minimum_required(VERSION 3.10)
project(RaiiFileExamples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

set(RAII_FILE_SRC
    src/raii_file.cpp
)

add_executable(example1 examples/example1.cpp ${RAII_FILE_SRC})
add_executable(example2 examples/example2.cpp ${RAII_FILE_SRC})
add_executable(example3 examples/example3.cpp ${RAII_FILE_SRC})