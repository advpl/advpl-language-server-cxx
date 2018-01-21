cmake_minimum_required(VERSION 3.9)

project(advpl_language_server_test)

find_package(Threads)
find_package(Boost
        REQUIRED
        log_setup
        log
        filesystem
        system
        thread
        serialization
        date_time
        regex
        unit_test_framework
        program_options
        locale
        REQUIRED)

set (Boost_NO_SYSTEM_PATHS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME OFF)
set (BOOST_ALL_DYN_LINK OFF)
add_definitions( -DBOOST_ALL_DYN_LINK )

ExternalProject_Get_Property(antlr4cpp INSTALL_DIR)
set (ANTLR_INSTALL_DIR ${INSTALL_DIR})

include_directories(
        ${Boost_INCLUDE_DIRS}
        ${ANTLR_INSTALL_DIR}/include/antlr4-runtime
        ${ADVPL_MAIN_SOURCE_DIR}/include
        ${ANTLR4CPP_GENERATED_SRC_DIR}/advplParser)

add_executable(${PROJECT_NAME}
    advpl_language_server_test.cpp)
target_link_libraries(${PROJECT_NAME}
        ${Boost_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
        ${ANTLR_INSTALL_DIR}/lib/libantlr4-runtime.so
        advpl_language_antlr_libraries
        advpl_language_server_cxx_modules)

add_test(NAME languageServerGeneralTest COMMAND ${PROJECT_NAME})

