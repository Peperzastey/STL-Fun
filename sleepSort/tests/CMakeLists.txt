set(SRC_FILES
    sleepSortTest.cpp
)

add_executable(sleepSortTest
    ${SRC_FILES}
)
target_link_libraries(sleepSortTest
    PRIVATE
        sleepSort
)
target_compile_options(sleepSortTest
    PRIVATE
        -Wall -Wextra -pedantic
)
target_compile_features(sleepSortTest
    PRIVATE
        cxx_std_17
)
set_target_properties(sleepSortTest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)

if(CLANG_TIDY_EXE)
    set_target_properties(sleepSortTest PROPERTIES
        CXX_CLANG_TIDY "${DO_CLANG_TIDY};${CLANG_TIDY_CHECKS}"
    )
endif()

add_test(sleepSortTest sleepSortTest)
