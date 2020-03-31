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

install(TARGETS ${TARGET} DESTINATION "${QT_PLUGINS_DIR}/kwin/effects/plugins")