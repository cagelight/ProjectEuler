cmake_minimum_required(VERSION 3.0.4)

set(ProjectEulerNum "0002")

enable_language(C CXX ASM_NASM)

set(ProjectIncludeDirectories ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB_RECURSE PECurFiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "*.h"
    "*.c"
    "*.hpp"
    "*.cpp"
    "*.asm"
)
source_group(${ProjectEulerNum} FILES ${PECurFiles})

PROJECT_EULER_LIBRARY(${ProjectEulerNum} "${PECurFiles}" "${ProjectIncludeDirectories}" "")
