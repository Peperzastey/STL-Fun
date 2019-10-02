set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

add_subdirectory(binary-search-ops)
add_subdirectory(linear-search-ops)

set(SRC_FILES
    dummyForCMake.cpp
)

add_executable(stlAlgorithmsTest
    ${SRC_FILES}
)
#TODO? Object Libraries instead of Interface Libraries?
target_link_libraries(stlAlgorithmsTest
    PRIVATE
        binarySearchOps
        linearSearchOps

        gtest
        gtest_main
        Threads::Threads
)
target_compile_options(stlAlgorithmsTest
    PRIVATE
        -Wall -Wextra -pedantic
)
target_compile_features(stlAlgorithmsTest
    PRIVATE
        cxx_std_17
)
set_target_properties(stlAlgorithmsTest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}
)

#lots of warnings because of gtest's code
#TODO do sth about it
# if(CLANG_TIDY_EXE)
#     set_target_properties(stlAlgorithmsTest PROPERTIES
#         CXX_CLANG_TIDY "${DO_CLANG_TIDY};${CLANG_TIDY_CHECKS}"
#     )
# endif()

add_test(NAME StlAlgorithmsTest
    COMMAND stlAlgorithmsTest
    WORKING_DIRECTORY $<TARGET_FILE_DIR:stlAlgorithmsTest>
)
