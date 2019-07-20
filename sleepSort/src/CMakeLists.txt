set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

set(SRC_FILES
    sleepSort.hpp
)

# header-only library
add_library(sleepSort INTERFACE)
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
