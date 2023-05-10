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

if (TESTS)
    set(EXECUTABLE tests)
    enable_testing()
    add_executable(${EXECUTABLE} ${SOURCE_FILES} tests.cpp)
else()
    set(EXECUTABLE core)
    add_library(${EXECUTABLE} SHARED ${SOURCE_FILES})
    target_include_directories(${EXECUTABLE} PUBLIC "./")
    #add_executable(${EXECUTABLE} main.cpp ${SOURCE_FILES})
endif()
target_link_libraries(${EXECUTABLE} Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(${EXECUTABLE} GTest::gtest_main)
install(TARGETS ${EXECUTABLE}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})



