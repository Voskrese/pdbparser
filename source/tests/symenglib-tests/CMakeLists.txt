
set(target symenglib-tests)
message(STATUS "Test ${target}")


# Includes

include_directories(
    
)

include_directories(
    BEFORE
    ${CMAKE_SOURCE_DIR}/source/symenglib/include/symenglib/
)


# Libraries

set(libs
    ${GMOCK_LIBRARIES}
    ${GTEST_LIBRARIES}
    symenglib
)


# Compiler definitions

if (OPTION_BUILD_STATIC)
    add_definitions("-D${META_PROJECT_NAME_UPPER}_STATIC")
endif()


# Sources

set(sources
    main.cpp
    firsh_test.cpp
    parce_pdb_test.cpp
)


# Build executable

add_executable(${target} ${sources})

target_link_libraries(${target} ${libs})

target_compile_options(${target} PRIVATE ${DEFAULT_COMPILE_FLAGS})

set_target_properties(${target}
    PROPERTIES
    LINKER_LANGUAGE              CXX
    FOLDER                      "${IDE_FOLDER}"
    COMPILE_DEFINITIONS_DEBUG   "${DEFAULT_COMPILE_DEFS_DEBUG}"
    COMPILE_DEFINITIONS_RELEASE "${DEFAULT_COMPILE_DEFS_RELEASE}"
    LINK_FLAGS_DEBUG            "${DEFAULT_LINKER_FLAGS_DEBUG}"
    LINK_FLAGS_RELEASE          "${DEFAULT_LINKER_FLAGS_RELEASE}"
    DEBUG_POSTFIX               "d${DEBUG_POSTFIX}")
