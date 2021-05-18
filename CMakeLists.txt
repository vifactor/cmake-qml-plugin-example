cmake_minimum_required(VERSION 3.0)
project(app VERSION 1.0 LANGUAGES CXX)

find_package(Qt5 REQUIRED COMPONENTS Quick Core Qml)

# We're using ${PROJECT_NAME} for target name but it's not necessary
add_executable(
    ${PROJECT_NAME}
    src/main.cpp        # Our example project consists only of one .cpp file
    ${CMAKE_CURRENT_LIST_DIR}/src/qml/app.qrc
)

set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC ON AUTORCC ON)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(
        ${PROJECT_NAME}
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
    )
endif()

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        Qt5::Core
        Qt5::Quick
        Qt5::Qml
        myplugin        # Our plugin target
)

add_subdirectory(plugins)
