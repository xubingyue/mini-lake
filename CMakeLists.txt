cmake_minimum_required(VERSION 2.8.6)


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


project(mini-lake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sources)

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
	add_definitions(/D_CRT_SECURE_NO_WARNINGS /wd"4244" /wd"4127" /wd"4702" /wd"4324" /wd"4267" /wd"4146")
endif()

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