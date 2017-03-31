cmake_minimum_required(VERSION 3.5)
project(QueryProcessing)

find_package(Boost 1.63.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES

    src/OperatorDictionary.cpp
    src/PointOperations.cpp
    src/QueryProcessing.cpp
    src/TestQueryProcessing.cpp src/RectangleOperations.cpp)

add_executable(QueryProcessing ${SOURCE_FILES})

if(Boost_FOUND)

    target_link_libraries(QueryProcessing ${Boost_LIBRARIES})

endif()