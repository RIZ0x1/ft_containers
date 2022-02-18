cmake_minimum_required(VERSION 3.16)
project(ft_containers)

set(ROOT_DIR ${CMAKE_SOURCE_DIR})
set(SRCS ${ROOT_DIR}/tests/ft_main.cpp)

set(HDRS
    ${ROOT_DIR}/vector/vector.hpp
    ${ROOT_DIR}/iterator/iterators_core.hpp
    ${ROOT_DIR}/iterator/ContiguousIterator.hpp
    ${ROOT_DIR}/ft_utils/enable_if.hpp
    ${ROOT_DIR}/ft_utils/is_integral.hpp
)

set(TPPS
    ${ROOT_DIR}/vector/vector.tpp
    ${ROOT_DIR}/iterator/ContiguousIterator.tpp
)

add_executable(ft_containers
    ${SRCS}
    ${HDRS}
    ${TPPS}
)

target_include_directories(ft_containers PUBLIC
    ${ROOT_DIR}/vector/
    ${ROOT_DIR}/iterator/
    ${ROOT_DIR}/ft_utils/
)

add_compile_options(-Wall -Wextra -Werror)
set_property(TARGET ft_containers PROPERTY CXX_STANDARD 98)
