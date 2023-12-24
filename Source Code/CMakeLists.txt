cmake_minimum_required(VERSION 3.16)

project(game VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appgame
    main.cpp
)

qt_add_qml_module(appgame
    URI game
    VERSION 1.0
    QML_FILES Main.qml

    RESOURCES
    audio/click.wav

    images/background.png
    images/tablebackground2.jpeg
    images/rejouer.png
    images/MENU.png
    images/commencer.png
    images/EkA5.gif

    images/Golden_star.png
    images/Silver_star.png

    images/f1.png
    images/f2.png
    images/m1.png
    images/m2.png
    images/d1.png
    images/d2.png

    images/1C.png
    images/1M.png
    images/1B.png
    images/1E.png

    images/2C.png
    images/2M.png
    images/2B.png
    images/2E.png

    images/3C.png
    images/3M.png
    images/3B.png
    images/3E.png

    images/4C.png
    images/4M.png
    images/4B.png
    images/4E.png

    images/5C.png
    images/5M.png
    images/5B.png
    images/5E.png

    images/6C.png
    images/6M.png
    images/6B.png
    images/6E.png

    images/7C.png
    images/7M.png
    images/7B.png
    images/7E.png

    images/10C.png
    images/10M.png
    images/10B.png
    images/10E.png

    images/11C.png
    images/11M.png
    images/11B.png
    images/11E.png

    images/12C.png
    images/12M.png
    images/12B.png
    images/12E.png


    images/back.png


    SOURCES carte.h carte.cpp
    SOURCES table.h table.cpp
    SOURCES joueur.h joueur.cpp
    SOURCES jeu.h jeu.cpp
    SOURCES cartesmasquees.h cartesmasquees.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appgame PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appgame
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appgame
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appgame
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
