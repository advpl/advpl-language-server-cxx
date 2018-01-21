cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(advpl_language_server_cxx_bin)

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

# Boost
set (Boost_NO_SYSTEM_PATHS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME OFF)
set (BOOST_ALL_DYN_LINK OFF)
add_definitions( -DBOOST_ALL_DYN_LINK )
if (WIN32)
    macro(get_WIN32_WINNT version)
        if (CMAKE_SYSTEM_VERSION)
            set(ver ${CMAKE_SYSTEM_VERSION})
            string(REGEX MATCH "^([0-9]+).([0-9])" ver ${ver})
            string(REGEX MATCH "^([0-9]+)" verMajor ${ver})
            # Check for Windows 10, b/c we'll need to convert to hex 'A'.
            if ("${verMajor}" MATCHES "10")
                set(verMajor "A")
                string(REGEX REPLACE "^([0-9]+)" ${verMajor} ver ${ver})
            endif ("${verMajor}" MATCHES "10")
            # Remove all remaining '.' characters.
            string(REPLACE "." "" ver ${ver})
            # Prepend each digit with a zero.
            string(REGEX REPLACE "([0-9A-Z])" "0\\1" ver ${ver})
            set(${version} "0x${ver}")
        endif(CMAKE_SYSTEM_VERSION)
    endmacro(get_WIN32_WINNT)
    ADD_DEFINITIONS(-DUNICODE)
    ADD_DEFINITIONS(-D_UNICODE)
    get_WIN32_WINNT(ver)
    add_definitions(-D_WIN32_WINNT=${ver})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd\"4251\"")
endif(WIN32)
# End Boost

ExternalProject_Get_Property(antlr4cpp INSTALL_DIR)
set (ANTLR_INSTALL_DIR ${INSTALL_DIR})

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
        ${Boost_INCLUDE_DIRS}
        ${ANTLR_INSTALL_DIR}/include/antlr4-runtime
        ${ANTLR4CPP_GENERATED_SRC_DIR}/advplParser)

add_library(advpl_language_server_cxx_modules
    modules/AdvplLSPCallbacks.cpp
    modules/AdvplLSPServer.cpp
    modules/JSONOutput.cpp
    modules/JSONRPCDispatcher.cpp
    modules/Logger.cpp
    modules/ProtocolHandlers.cpp)

add_executable(${PROJECT_NAME} AdvplLanguageServer.cpp)
target_link_libraries(${PROJECT_NAME}
        ${Boost_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
        ${ANTLR_INSTALL_DIR}/lib/libantlr4-runtime.so
        advpl_language_antlr_libraries
        advpl_language_server_cxx_modules)

