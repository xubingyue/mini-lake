cmake_minimum_required(VERSION 2.8.6)


include(CheckCXXSourceRuns)

include(CheckIncludeFileCXX)

include(CheckTypeSize)

include(CheckIncludeFiles)

include(CheckFunctionExists)


project(mini-lake)

###########################################################################################

#auto find the c/c++ files

set(C_CXX_EXTENSIONS "*.h;*.hpp;*.c;*.cpp;*.cc;*.cxx")


foreach(E ${C_CXX_EXTENSIONS})
	file(GLOB_RECURSE FOUND ${E})
	list(APPEND C_CXX_FILES ${FOUND})
endforeach()


foreach(F ${C_CXX_FILES})
	get_filename_component(FILE_NAME ${F} NAME)
	string(REPLACE ${FILE_NAME} "" DIRECTORY ${F})
	#get the relative path to sources directory
	file(RELATIVE_PATH DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} ${DIRECTORY})
	file(TO_NATIVE_PATH "${DIRECTORY}" DIRECTORY)
	source_group("${DIRECTORY}" FILES ${F})
endforeach()

########################################################################################################################################

include(${CMAKE_CURRENT_SOURCE_DIR}/sources/lake/inttypes.cmake)

check_function_exists(localtime_r LEMON_HAS_LOCALTIME_R)

check_function_exists(gmtime_r LEMON_HAS_GMTIME_R)

check_function_exists(localtime LEMON_HAS_LOCALTIME)

check_function_exists(gmtime LEMON_HAS_GMTIME)

check_function_exists(gettimeofday LEMON_HAS_GETTIMEOFDAY)

check_cxx_source_runs("void test(int &&){}\n int main(){ return 0;}" LEMON_COMPILER_SUPPORT_RVALUE)

check_cxx_source_runs("struct __declspec(align(1)) test{char a;}; int main(){return 0;} " LEMON_COMPILER_SUPPORT_DECLSPEC_ALIGNED)

check_cxx_source_runs("struct __attribute__((__aligned__((1)))) test{char a;}; int main(){return 0;}" LEMON_COMPILER_SUPPORT_ATTRIBUTE_ALIGNED)

check_cxx_source_runs(" int main(){__is_abstract(int); return 0;}" LEMON_COMPILER_SUPPORT_IS_ABSTRACT)

check_cxx_source_runs(" int main(){__is_base_of(int,char); return 0;}" LEMON_COMPILER_SUPPORT_IS_BASE_OF)

check_cxx_source_runs(" int main(){__is_class(int); return 0;}" LEMON_COMPILER_SUPPORT_IS_CLASS)

check_cxx_source_runs(" int main(){__is_enum(int); return 0;}" LEMON_COMPILER_SUPPORT_IS_ENUM)

check_cxx_source_runs(" int main(){__is_pod(int); return 0;}" LEMON_COMPILER_SUPPORT_IS_POD)

check_cxx_source_runs(" int main(){__has_trivial_constructor(int); return 0;}" LEMON_COMPILER_SUPPORT_HAS_TRIVIAL_CONSTRUCTOR)

check_cxx_source_runs(" int main(){long long a = 0; return 0;}" LEMON_COMPILER_SUPPORT_LONGLONG)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/sources/lemonxx/configure.h.in ${PROJECT_BINARY_DIR}/build/sources/lemonxx/configure.h IMMEDIATE)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/sources/lake/configure.h.in ${PROJECT_BINARY_DIR}/build/sources/lake/configure.h IMMEDIATE)

source_group("sources\\lemonxx" FILES ${PROJECT_BINARY_DIR}/build/sources/lemonxx/configure.h)

source_group("sources\\lake" FILES ${PROJECT_BINARY_DIR}/build/sources/lake/configure.h)

list(APPEND C_CXX_FILES ${PROJECT_BINARY_DIR}/build/sources/lemonxx/configure.h ${PROJECT_BINARY_DIR}/build/sources/lake/configure.h)

########################################################################################################################################

if(MSVC)
    foreach(flag_var CMAKE_C_FLAGS_DEBUG CMAKE_CXX_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE CMAKE_CXX_FLAGS_RELEASE CMAKE_C_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO CMAKE_CXX_FLAGS_RELWITHDEBINFO) 
        string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
        string(REGEX REPLACE "/MDd" "/MTd" ${flag_var} "${${flag_var}}")
    endforeach(flag_var)
    SET (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}" CACHE STRING "MSVC C Debug MT flags " FORCE)    
    SET (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}" CACHE STRING "MSVC CXX Debug MT flags " FORCE)
    SET (CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}" CACHE STRING "MSVC C Release MT flags " FORCE)
    SET (CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}" CACHE STRING "MSVC CXX Release MT flags " FORCE)
    SET (CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL}" CACHE STRING "MSVC C Debug MT flags " FORCE)    
    SET (CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL}" CACHE STRING "MSVC C Release MT flags " FORCE)
    SET (CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO}" CACHE STRING "MSVC CXX Debug MT flags " FORCE)    
    SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}" CACHE STRING "MSVC CXX Release MT flags " FORCE)
endif()

#disable lua library compile warning on MSVC
if(WIN32)
	add_definitions(/WX /W4 /D_UNICODE /DUNICODE)
	add_definitions(/D_CRT_SECURE_NO_WARNINGS /wd"4244" /wd"4127" /wd"4702" /wd"4324" /wd"4267" /wd"4146" /wd"4100" /wd"4189" /wd"4701")
endif()


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sources ${PROJECT_BINARY_DIR}/build/sources/)

add_executable(mini-lake ${C_CXX_FILES})

####################################################################################

 SET_TARGET_PROPERTIES(
    mini-lake PROPERTIES 
    
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/build/lib/
    
    LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/build/lib/
    
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_BINARY_DIR}/build/bin/
    )
  SET_TARGET_PROPERTIES(
    mini-lake PROPERTIES 
    
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR}/build/lib/
    
    LIBRARY_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR}/build/lib/
    
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_BINARY_DIR}/build/bin/
    )
  SET_TARGET_PROPERTIES(
    mini-lake PROPERTIES 
    
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/build/lib/
    
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/build/lib/
    
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/build/bin/
    )