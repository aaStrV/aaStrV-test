cmake_minimum_required (VERSION 2.6)

project (aaStrV-test1)

include_directories("/usr/src/gtest/include/gtest/")
link_directories("$ENV{HOME}/install/gtest/build")
find_package(GTest)

add_executable(main main.cpp test1.cpp test2.cpp test3.cpp test4.cpp test5.cpp)
add_executable(main-gtest main-gtest.cpp test1.cpp test2.cpp test3.cpp test4.cpp test5.cpp)
target_link_libraries(main gtest pthread)
target_link_libraries(main-gtest gtest pthread)
gtest_discover_tests(main-gtest)
