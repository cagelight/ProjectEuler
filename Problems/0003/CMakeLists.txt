cmake_minimum_required(VERSION 3.0.4)

enable_language(C CXX ASM_NASM)

get_filename_component(PE_ID ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(ProjectIncludeDirectories ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB_RECURSE PECurFiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "*.h"
    "*.c"
    "*.hpp"
    "*.cpp"
    "*.asm"
)
source_group(${PE_ID} FILES ${PECurFiles})

PROJECT_EULER_LIBRARY(${PE_ID} "${PECurFiles}" "${ProjectIncludeDirectories}" "")
