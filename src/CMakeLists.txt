cmake_minimum_required(VERSION 3.10)
project(can_tech)

set(CMAKE_C_STANDARD 11)

include_directories(includes)

set(APP_NAME "can_tech")
set(APP_VERSION "1.0.0")
set(TARGET ${APP_NAME})
set(RELEASE_OUTPUT_DIR "${CMAKE_BINARY_DIR}/Release")
set(DEBUG_OUTPUT_DIR "${CMAKE_BINARY_DIR}/Debug")

set(CAN_TECH_MAIN_SRCS
  # Entry
  main.c
)

set(CAN_TECH_BUS_SRCS
  bus/can_bus.c
)
source_group(bus FILES ${CAN_TECH_BUS_SRCS})

set(CAN_TECH_SRCS
  ${CAN_TECH_MAIN_SRCS}
  ${CAN_TECH_BUS_SRCS}
)



#
# Linux configuration.
#

if(UNIX)
  add_executable(${TARGET} ${CAN_TECH_SRCS})

  set_target_properties(${TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${RELEASE_OUTPUT_DIR}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${DEBUG_OUTPUT_DIR}
  )
endif()