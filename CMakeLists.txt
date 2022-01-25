cmake_minimum_required(VERSION 3.16)
project(ft_containers)

#USER VARIABLES
set(ROOT_DIR ${CMAKE_SOURCE_DIR})
set(SRCS ${ROOT_DIR}/tests/ft_main.cpp)

set(HDRS
    ${ROOT_DIR}/vector/vector.hpp
    ${ROOT_DIR}/iterator/iterators_core.hpp
    ${ROOT_DIR}/iterator/iterators.hpp
)

set(TPPS
    ${ROOT_DIR}/vector/vector.tpp
    ${ROOT_DIR}/iterator/iterators.tpp
)

add_executable(ft_containers
    ${SRCS}
    ${HDRS}
    ${TPPS}
)

target_include_directories(ft_containers PUBLIC
    ${ROOT_DIR}/vector/
    ${ROOT_DIR}/iterator/
)
