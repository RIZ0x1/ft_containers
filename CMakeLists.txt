cmake_minimum_required(VERSION 3.16)
project(ft_containers)

set(ROOT_DIR ${CMAKE_SOURCE_DIR})

set(SRCS # TEST FILE
    ${ROOT_DIR}/tests/stack.cpp
)

set(HDRS
    ${ROOT_DIR}/vector/vector.hpp
    ${ROOT_DIR}/stack/stack.hpp
    ${ROOT_DIR}/map/map.hpp
    ${ROOT_DIR}/map/BinarySearchTree.hpp
    ${ROOT_DIR}/map/pair.hpp
    ${ROOT_DIR}/iterator/iterators_core.hpp
    ${ROOT_DIR}/iterator/ContiguousIterator.hpp
    ${ROOT_DIR}/iterator/BidirectionalIterator.hpp
    ${ROOT_DIR}/ft_utils/enable_if.hpp
    ${ROOT_DIR}/ft_utils/is_integral.hpp
    ${ROOT_DIR}/ft_utils/lexicographical_compare.hpp
)

set(TPPS
    ${ROOT_DIR}/vector/vector.tpp
    ${ROOT_DIR}/map/map.tpp
    ${ROOT_DIR}/map/BinarySearchTree.tpp
    ${ROOT_DIR}/map/pair.tpp
    ${ROOT_DIR}/iterator/ContiguousIterator.tpp
    ${ROOT_DIR}/iterator/BidirectionalIterator.tpp
)

add_executable(ft_containers
    ${SRCS}
    ${HDRS}
    ${TPPS}
)

target_include_directories(ft_containers PUBLIC
    ${ROOT_DIR}/vector/
    ${ROOT_DIR}/stack/
    ${ROOT_DIR}/map/
    ${ROOT_DIR}/iterator/
    ${ROOT_DIR}/ft_utils/
)

add_compile_options(-Wall -Wextra -Werror)
set_property(TARGET ft_containers PROPERTY CXX_STANDARD 98)
