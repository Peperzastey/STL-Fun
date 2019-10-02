add_library(binarySearchOps INTERFACE)
target_sources(binarySearchOps
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/lower_bound.cpp
)
