project (panda-decoration)
set(CMAKE_CXX_STANDARD 11)

find_package(KF5CoreAddons REQUIRED)
find_package(KF5Config REQUIRED)
find_package(KF5WindowSystem REQUIRED)
find_package(KDecoration2 REQUIRED)
find_package(Qt5 CONFIG REQUIRED COMPONENTS Gui Core)

set (decoration_SRCS
    decoration.cpp
    boxshadowhelper.cpp
    closebutton.cpp
    maximizebutton.cpp
    minimizebutton.cpp
)

add_library (panda-decoration MODULE
    ${decoration_SRCS}
)

target_link_libraries (panda-decoration
    PUBLIC
        Qt5::Core
        Qt5::Gui
        KF5::ConfigCore
        KF5::ConfigGui
        KF5::CoreAddons
        KF5::WindowSystem

    PRIVATE
        KDecoration2::KDecoration
)

install (TARGETS panda-decoration
         DESTINATION ${QT_PLUGINS_DIR}/org.kde.kdecoration2)
