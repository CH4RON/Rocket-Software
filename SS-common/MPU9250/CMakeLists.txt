set(TARGET MPU9250)

add_library(${TARGET} INTERFACE)

target_include_directories(
        ${TARGET} INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(${TARGET} INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/SS_MPU9250.h
        ${CMAKE_CURRENT_SOURCE_DIR}/SS_AK8963.c
        ${CMAKE_CURRENT_SOURCE_DIR}/SS_AK8963.h)

target_non_test_sources(${TARGET} INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/SS_MPU9250.c)

target_test_sources(${TARGET} INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/SS_MPU9250_tests.c)
