set(SRC_FILES
    sleepSortTest.cpp
)

add_executable(sleepSortTest ${SRC_FILES})
# source argument optional since version 3.11
#target_sources(sleepSortTest
#    PRIVATE
#        ${SRC_FILES}
#)
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

add_test(sleepSortTest sleepSortTest)
