set(TARGET FreeRTOS_setup)

add_library(${TARGET} INTERFACE)

target_include_directories(
        ${TARGET} INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${TARGET} INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/SS_FreeRTOS.c
        ${CMAKE_CURRENT_SOURCE_DIR}/SS_FreeRTOS.h)
