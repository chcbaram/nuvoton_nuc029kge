cmake_minimum_required(VERSION 3.13)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tools")
include(arm-none-eabi-gcc)


set(PRJ_NAME nuc029kge_fw)


project(${PRJ_NAME}
  LANGUAGES ASM C CXX
)


set(EXECUTABLE ${PRJ_NAME}.elf)


file(GLOB SRC_FILES CONFIGURE_DEPENDS
  src/bsp/*.c
  src/hw/*.c
  src/hw/driver/*.c
)

file(GLOB_RECURSE SRC_FILES_RECURSE CONFIGURE_DEPENDS
  src/ap/*.c
  src/common/*.c    
  src/lib/NUC029xGE/*.c
)

add_executable(${EXECUTABLE} 
  src/main.c
  src/bsp/startup/startup_NUC029xGE.S

  ${SRC_FILES}
  ${SRC_FILES_RECURSE}
)



target_include_directories(${EXECUTABLE} PRIVATE 
  src  
  src/ap
  src/bsp
  src/common 
  src/common/core
  src/common/hw/include 
  src/hw
  src/lib
    
  src/lib/NUC029xGE/CMSIS/Include
  src/lib/NUC029xGE/NuClockConfig/clock
  src/lib/NUC029xGE/StdDriver/inc
)

target_compile_definitions(${EXECUTABLE} PRIVATE
  )

target_compile_options(${EXECUTABLE} PRIVATE
  -mcpu=cortex-m0
  -mthumb
# -mfpu=fpv4-sp-d16 
# -mfloat-abi=hard

  -fsigned-char
  -fdata-sections
  -ffunction-sections
  -fsingle-precision-constant
  -Wall

  -g3
  -O0
  )

target_link_options(${EXECUTABLE} PRIVATE
  -T${CMAKE_CURRENT_SOURCE_DIR}/src/bsp/ldscript/gcc_arm.ld
  -mcpu=cortex-m0
  -mthumb
# -mfpu=fpv4-sp-d16 
# -mfloat-abi=hard
  -specs=nano.specs
  -lc
  -lm
  -lstdc++
  -lsupc++
  # -lnosys
  -Wl,-Map=${PRJ_NAME}.map,--cref
  -Wl,--gc-sections
  -Xlinker -print-memory-usage -Xlinker
  )

target_link_libraries( ${EXECUTABLE} PRIVATE
  )

add_custom_command(TARGET ${EXECUTABLE} 
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} ARGS -O binary ${EXECUTABLE} ${PROJECT_NAME}.bin
    COMMENT "Invoking: Make Binary"
    )

#set_target_properties(${EXECUTABLE} PROPERTIES SUFFIX ".elf")
#add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
#        COMMAND arm-none-eabi-size --format=berkeley --totals "$<TARGET_FILE:${EXECUTABLE}>"
#        COMMENT "Invoking: Cross ARM GNU Print Size")