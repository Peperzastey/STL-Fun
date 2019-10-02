add_library(linearSearchOps INTERFACE)
target_sources(linearSearchOps
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/adjacent_find.cpp
)
