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

    src/query-processing/OperatorDictionary.cpp
    src/query-processing/PointOperations.cpp
    src/query-processing/QueryProcessing.cpp
    src/query-processing/TestQueryProcessing.cpp
    src/query-processing/RectangleOperations.cpp src/integration/PointOperations.h src/integration/RectangleOperations.h)

add_executable(QueryProcessing ${SOURCE_FILES})

if(Boost_FOUND)

    target_link_libraries(QueryProcessing ${Boost_LIBRARIES})

endif()