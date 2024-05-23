cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(cpp-examples LANGUAGES CXX)

# set cxx standard
if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 11)
endif()
message(--\ CMAKE_CXX_STANDARD\ =\ ${CMAKE_CXX_STANDARD})

if(${CMAKE_CXX_STANDARD} STREQUAL "11")
    add_compile_definitions(CXX_STANDARD_11)
elseif(${CMAKE_CXX_STANDARD} STREQUAL "14")
    add_compile_definitions(CXX_STANDARD_11 CXX_STANDARD_14)
elseif(${CMAKE_CXX_STANDARD} STREQUAL "17")
    add_compile_definitions(CXX_STANDARD_11 CXX_STANDARD_14 CXX_STANDARD_17)
elseif(${CMAKE_CXX_STANDARD} STREQUAL "20")
    add_compile_definitions(CXX_STANDARD_11 CXX_STANDARD_14 CXX_STANDARD_17 CXX_STANDARD_20)
elseif(${CMAKE_CXX_STANDARD} STREQUAL "23")
    add_compile_definitions(CXX_STANDARD_11 CXX_STANDARD_14 CXX_STANDARD_17 CXX_STANDARD_20  CXX_STANDARD_23)
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# deny warnings
add_compile_options(-Werror)

# setup top include directory
include_directories(${CMAKE_SOURCE_DIR})

# subdirectories
add_subdirectory(type_system)
add_subdirectory(container)
add_subdirectory(basic_types)