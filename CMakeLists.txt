cmake_minimum_required(VERSION 3.9)

project(StlFun CXX)

include(CTest)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CLANG_TIDY_CHECKS
    "-checks=clang-analyzer-*,cppcoreguidelines-*,modernize-*,readability-*,performance-*,,misc-*,bugprone-*,cert-*"
    CACHE STRING "Default clang-tidy checks for this project"
)

#TODO move to separate CMake module and add IMPORTED executable
if(CMAKE_VERSION VERSION_GREATER 3.6)
    # Add clang-tidy if available
    option(CLANG_TIDY_FIX "Perform fixes for Clang-Tidy" OFF)

    message(STATUS "Looking for clang-tidy executable")
    find_program(
        CLANG_TIDY_EXE
        NAMES clang-tidy clang-tidy-8 clang-tidy-7 NAMES_PER_DIR
        DOC "Path to clang-tidy executable"
    )

    if(NOT CLANG_TIDY_EXE)
        message(STATUS "Looking for clang-tidy executable - not found")
    else()
        message(STATUS "Looking for clang-tidy executable - found: ${CLANG_TIDY_EXE}")
        if(CLANG_TIDY_FIX)
            set(DO_CLANG_TIDY "${CLANG_TIDY_EXE}" "-fix")
        else()
            set(DO_CLANG_TIDY "${CLANG_TIDY_EXE}")
        endif()
    endif()
endif()

add_subdirectory(sleepSort)
