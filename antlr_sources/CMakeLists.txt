cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

ExternalProject_Get_Property(antlr4cpp INSTALL_DIR)
set (ANTLR_INSTALL_DIR ${INSTALL_DIR})

project(advpl_language_antlr_libraries)

include_directories(
        ${ANTLR_INSTALL_DIR}/include/antlr4-runtime
        ${ANTLR4CPP_GENERATED_SRC_DIR}/advplParser)

add_library(${PROJECT_NAME}
    ${ANTLR4CPP_GENERATED_SRC_DIR}/advplParser/AdvplBaseListener.cpp
    ${ANTLR4CPP_GENERATED_SRC_DIR}/advplParser/AdvplLexer.cpp
    ${ANTLR4CPP_GENERATED_SRC_DIR}/advplParser/AdvplParser.cpp
    ${ANTLR4CPP_GENERATED_SRC_DIR}/advplParser/AdvplBaseVisitor.cpp
    ${ANTLR4CPP_GENERATED_SRC_DIR}/advplParser/AdvplListener.cpp
    ${ANTLR4CPP_GENERATED_SRC_DIR}/advplParser/AdvplVisitor.cpp)

