cmake_minimum_required(VERSION 3.13)
project(GBP_Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(GBP_Server Main/main.cpp Server/Server.cpp Logic/Cell.cpp Logic/Cell.h Logic/Matrix.cpp Logic/Matrix.h Structures/List.h Structures/Node.h Logic/JSONManager.cpp Logic/JSONManager.h Genetics/Gladiator.cpp Genetics/Gladiator.h Genetics/Population.cpp Genetics/Population.h Genetics/Fitness.cpp Genetics/Fitness.h Genetics/Algorithm.cpp Genetics/Algorithm.h Tests/test.cpp Tests/TestGenetic.cpp)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
target_link_libraries(GBP_Server gtest gtest_main)

