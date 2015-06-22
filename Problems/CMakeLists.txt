cmake_minimum_required(VERSION 3.0.4)

macro(PROJECT_EULER_LIBRARY BIN FILES INCS LIBS)
    add_library(${BIN} SHARED ${FILES})
    install(TARGETS ${BIN} LIBRARY DESTINATION ".")
    set_target_properties(${BIN} PROPERTIES PREFIX "")
    set_target_properties(${BIN} PROPERTIES SUFFIX "")
    set_target_properties(${BIN} PROPERTIES INCLUDE_DIRECTORIES ${INCS})
    set_target_properties(${BIN} PROPERTIES PROJECT_LABEL "${ProjectName}")
    target_link_libraries(${BIN} ${LIBS})
endmacro()

macro(PROJECT_EULER_SUBPROJECT)
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
endmacro()

file(GLOB PE_Subdirs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach(PE_Sub ${PE_Subdirs})
if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${PE_Sub})
    ADD_SUBDIRECTORY(${PE_Sub})
endif()
endforeach()
