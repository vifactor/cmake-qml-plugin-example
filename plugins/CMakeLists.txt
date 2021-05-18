# This is 'myplugin' CMakeLists.txt file. 'myplugin' is application plugin.
# It means that it was created specailly for 'app' project and probably
# will be never used outside of it.
# If you're goind to create reusable plugin make sure to build it as
# separate project with proper install commands and CMake.config file.

add_library(
    myplugin
    STATIC

    ${CMAKE_CURRENT_LIST_DIR}/my/plugin/example/myplugin.h
    ${CMAKE_CURRENT_LIST_DIR}/my/plugin/example/myquickitem.h

    ${CMAKE_CURRENT_LIST_DIR}/my/plugin/example/myplugin.cpp
    ${CMAKE_CURRENT_LIST_DIR}/my/plugin/example/myquickitem.cpp

    # It's not important to include 'qmldir' or 'plugin.qmltypes' here,
    # but it will make IDEs (such as Qt Creator) to include them in project tree
    ${CMAKE_CURRENT_LIST_DIR}/my/plugin/example/qmldir
#    ${CMAKE_CURRENT_LIST_DIR}/plugin.qmltypes

    ${CMAKE_CURRENT_LIST_DIR}/my/plugin/example/plugin.qrc
)

set_target_properties(myplugin PROPERTIES AUTOMOC ON AUTORCC ON)
target_compile_definitions(myplugin PUBLIC QT_STATICPLUGIN)

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
    myplugin
    PRIVATE
        Qt5::Core
        Qt5::Quick
        Qt5::Qml
)

# During plugin searching Qt will be looking for 'qmldir' file
# So we should place it next to our plugin lib.
#add_custom_command(
#    TARGET myplugin
#    POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_LIST_DIR}/qmldir $<TARGET_FILE_DIR:myplugin>/qmldir
#)
