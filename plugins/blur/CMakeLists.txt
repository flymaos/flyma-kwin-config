set(TARGET "panda-blur")

find_package(KF5Config REQUIRED)
find_package(Qt5 CONFIG REQUIRED COMPONENTS Core Gui)
find_package(KF5CoreAddons REQUIRED)
find_package(KF5WindowSystem REQUIRED)

add_library(
    ${TARGET} MODULE
    blur.cpp
    blurshader.cpp
    main.cpp
)

target_link_libraries(
    ${TARGET}
    PUBLIC
    Qt5::Core
    Qt5::Gui
    PRIVATE
    KF5::CoreAddons
    KF5::WindowSystem
    KF5::ConfigCore
)

# 获取qmake
get_target_property(QT_QMAKE_EXECUTABLE ${Qt5Core_QMAKE_EXECUTABLE} IMPORTED_LOCATION)
if(NOT QT_QMAKE_EXECUTABLE)
    message(FATAL_ERROR "qmake is not found.")
endif()

# execute the command "qmake -query QT_INSTALL_PLUGINS" to get the path of plugins dir.
execute_process(COMMAND ${QT_QMAKE_EXECUTABLE} -query QT_INSTALL_PLUGINS
    OUTPUT_VARIABLE QT_PLUGINS_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
if(QT_PLUGINS_DIR)
    message(STATUS "Qt5 plugin directory:" "${QT_PLUGINS_DIR}")
else()
    message(FATAL_ERROR "Qt5 plugin directory cannot be detected.")
endif()

install(TARGETS ${TARGET} DESTINATION "${QT_PLUGINS_DIR}/kwin/effects/plugins")