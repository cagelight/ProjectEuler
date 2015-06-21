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

add_subdirectory(0001)
add_subdirectory(0002)
