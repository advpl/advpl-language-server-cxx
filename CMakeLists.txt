cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(advpl-language-server-cxx)
LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )
set(ANTLR4CPP_JAR_LOCATION c:/antlr4/antlr-4.7.1-complete.jar)
include(ExternalAntlr4Cpp)

message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS} ")
#Boost
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

set (BOOST_ROOT "C:/local/boost_1_65_1" )
set (Boost_NO_SYSTEM_PATHS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_STATIC_RUNTIME OFF)
set (BOOST_ALL_DYN_LINK OFF)
find_package(Boost REQUIRED log_setup log filesystem system thread serialization date_time regex  unit_test_framework program_options locale REQUIRED)
include_directories( include/)
include_directories(${Boost_INCLUDE_DIRS})
#EndBoost



project(advpl-language-server-cxx)
# # Call macro to add lexer and grammar to your build dependencies.
 antlr4cpp_process_grammar(${PROJECT_NAME} advplParser
   ${CMAKE_CURRENT_SOURCE_DIR}/grammar/Advpl.g4
   ${CMAKE_CURRENT_SOURCE_DIR}/grammar/Advpl.g4)
include_directories( ${ANTLR4CPP_INCLUDE_DIRS} )
# # include generated files in project environment
include_directories(${antlr4cpp_include_dirs_advplParser})

link_directories( ${ANTLR4CPP_LIBS} )

file(GLOB_RECURSE sources src/*.cpp )

include_directories( include/)

#include_directories( src/parser_generated)
#include_directories(${Boost_INCLUDE_DIRS})

# add_executable(demo main.cpp ${antlr4cpp_src_files_advplParser})
add_executable(${PROJECT_NAME} ${sources} ${antlr4cpp_src_files_advplParser})
add_dependencies(${PROJECT_NAME} antlr4cpp antlr4cpp_generation_advplParser)
target_link_libraries(${PROJECT_NAME} antlr4-runtime ${Boost_LIBRARIES} )

#add_dependencies(demo antlr4cpp antlr4cpp_generation_advplParser)
# target_link_libraries(demo antlr4-runtime)
