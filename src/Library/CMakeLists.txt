#
# Copyright (C) 2020-2022 QuasarApp.
# Distributed under the GPLv3 software license, see the accompanying
# Everyone is permitted to copy and distribute verbatim copies
# of this license document, but changing it is not allowed.
#

cmake_minimum_required(VERSION 3.14)

add_definitions(-DQT_NATIVETR_LIBRARY)

set(QT_TRANSLATIONS_PATH "${Qt${QT_VERSION_MAJOR}_DIR}/../../../translations")
file(GLOB QT_TRANSLATIONS_QM
    "${QT_TRANSLATIONS_PATH}/*.qm"
    "${QT_TRANSLATIONS_PATH}/*/*.qm"
)

set(RESOURCES_LIST)
foreach(QT_QM ${QT_TRANSLATIONS_QM})
    get_filename_component(QT_QM_NAME ${QT_QM} NAME)
    message("Deploy : ${QT_QM}")
    file(COPY "${QT_QM}" DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/languages/")
    string(APPEND RESOURCES_LIST "<file>languages/${QT_QM_NAME}</file>\n        ")
endforeach()

set(resources_file "${CMAKE_CURRENT_SOURCE_DIR}/QtNativeTr.qrc")
configure_file("${resources_file}.in" ${resources_file} @ONLY)


file(GLOB SOURCE_CPP
    "src/public/*.cpp"
    "src/public/QtNativeTr/*.cpp"
    "src/private/*.cpp"

    "src/public/*.h"
    "src/public/QtNativeTr/*.h"
    "src/private/*.h"
)

file(GLOB SOURCE_QRC
    "*.qrc"
)

set(PUBLIC_INCUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/public")
set(PRIVATE_INCUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/private")


add_library(${PROJECT_NAME} ${SOURCE_CPP} ${SOURCE_QRC})

target_link_libraries(${PROJECT_NAME} PUBLIC Qt${QT_VERSION_MAJOR}::Core )

target_include_directories(${PROJECT_NAME} PUBLIC ${PUBLIC_INCUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${PRIVATE_INCUDE_DIR})

set(global_file "${CMAKE_CURRENT_SOURCE_DIR}/src/public/QtNativeTr/global.h")
configure_file("${global_file}.in" ${global_file} @ONLY)


