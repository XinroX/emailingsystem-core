cmake_minimum_required(VERSION 3.14)

project(emailingsystem-core LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(GTest CONFIG REQUIRED)

option(TESTS "Specifies if tests are run" OFF)
set(SOURCE_FILES
    message.h message.cpp ISerialize.h ideserialize.h
    serializer.h serializer.cpp
    deserializer.h deserializer.cpp
)

set(EXECUTABLE core)
add_library(${EXECUTABLE} SHARED ${SOURCE_FILES})
add_executable(testRunner ${SOURCE_FILES} tests.cpp)
target_link_libraries(testRunner Qt${QT_VERSION_MAJOR}::Core GTest::gtest_main)
target_link_libraries(${EXECUTABLE} Qt${QT_VERSION_MAJOR}::Core)
install(TARGETS ${EXECUTABLE}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})



