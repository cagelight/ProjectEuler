cmake_minimum_required(VERSION 3.0.4)

enable_language(CXX)

set(ProjectSubDir "${CMAKE_CURRENT_SOURCE_DIR}")

set(ProjectIncludeDirectories ${CMAKE_CURRENT_BINARY_DIR})
set(ProjectFiles "${ProjectSubDir}/main.cpp")
source_group("project" FILES ${ProjectFiles})
set(ProjectLibs "-ldl")

set(ProjectBinary "projeuler")
add_executable(${ProjectBinary} ${ProjectFiles})
install(TARGETS ${ProjectBinary} RUNTIME DESTINATION ".")
set_target_properties(${ProjectBinary} PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO "PROJECT_RELEASE")
set_target_properties(${ProjectBinary} PROPERTIES COMPILE_DEFINITIONS_MINSIZEREL "PROJECT_RELEASE")
set_target_properties(${ProjectBinary} PROPERTIES COMPILE_DEFINITIONS_RELEASE "PROJECT_RELEASE")
set_target_properties(${ProjectBinary} PROPERTIES COMPILE_DEFINITIONS_DEBUG "PROJECT_DEBUG")
set_target_properties(${ProjectBinary} PROPERTIES INCLUDE_DIRECTORIES ${ProjectIncludeDirectories})
set_target_properties(${ProjectBinary} PROPERTIES PROJECT_LABEL "${ProjectName}")
target_link_libraries(${ProjectBinary} ${ProjectLibs})
