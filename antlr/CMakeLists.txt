cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(advpl_language_server_cxx_antlr)

set(ANTLR4CPP_EXTERNAL_REPO "https://github.com/antlr/antlr4.git")
set(ANTLR4CPP_EXTERNAL_TAG  "4.7.1")
set(ANTLR4CPP_JAR_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/antlr-${ANTLR4CPP_EXTERNAL_TAG}-complete.jar)
include(ExternalAntlr4Cpp)
message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS} ")

include_directories(
        ${ANTLR4CPP_INCLUDE_DIRS}
        ${ANTLR4CPP_GENERATED_SRC_DIR}/advplParser)

# Call macro to add lexer and grammar to your build dependencies.
antlr4cpp_process_grammar(
        ${PROJECT_NAME} advplParser
        ${CMAKE_CURRENT_SOURCE_DIR}/grammar/Advpl.g4
        ${CMAKE_CURRENT_SOURCE_DIR}/grammar/Advpl.g4)

project(advpl_language_server_cxx_antlr)
add_executable(${PROJECT_NAME} src/main.cpp)
add_dependencies(${PROJECT_NAME} antlr4cpp antlr4cpp_generation_advplParser)

