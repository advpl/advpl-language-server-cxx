cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(advpl_language_server_cxx
        VERSION 1.0.0
        DESCRIPTION "C++ Implementation of the Language Server Protocol for ADVPL")

LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(ADVPL_MAIN_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(ANTLR4CPP_GENERATED_SRC_DIR ${PROJECT_SOURCE_DIR}/antlr_sources)

add_subdirectory(antlr)
add_subdirectory(antlr_sources)
add_subdirectory(src)

enable_testing()
add_subdirectory(test)

add_dependencies(advpl_language_antlr_libraries advpl_language_server_cxx_antlr)
add_dependencies(advpl_language_server_cxx_modules advpl_language_antlr_libraries)
add_dependencies(advpl_language_server_cxx_bin advpl_language_server_cxx_modules)
add_dependencies(advpl_language_server_test advpl_language_server_cxx_bin)

