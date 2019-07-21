set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

# header-only library
add_library(sleepSort INTERFACE)
#TODO target_sources() + HEADER_FILE_ONLY property on source file
# target_sources(sleepSort
#     INTERFACE
#         # ${SRC_FILES}
#         #${CMAKE_CURRENT_SOURCE_DIR}/sleepSort.hpp
# )
target_include_directories(sleepSort
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(sleepSort
    INTERFACE
        Threads::Threads
)
target_compile_features(sleepSort
    INTERFACE
        cxx_std_14
)

if(CLANG_TIDY_EXE)
    set(CLANG_TIDY_HEADER_CHECKS
        "-header-filter=.*"
        ${CLANG_TIDY_CHECKS}
    )
    set(DUMMY_NAME "sleepSortClangTidyDummy")
    add_executable(${DUMMY_NAME} dummy.cpp)
    # target_compile_options(dummy
    #     PRIVATE
    #         -Wall -Wextra -pedantic
    # )
    target_link_libraries(${DUMMY_NAME}
        PRIVATE
            sleepSort
    )
    set_target_properties(${DUMMY_NAME} PROPERTIES
        OUTPUT_NAME "dummy"
    )
    set_target_properties(${DUMMY_NAME} PROPERTIES
        CXX_CLANG_TIDY "${DO_CLANG_TIDY};${CLANG_TIDY_HEADER_CHECKS}"
    )
endif()
