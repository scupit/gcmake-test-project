################################################################################
# Generated with Skylar Cupit's json-to-cmake tool
# Github: https://github.com/scupit/json-to-cmake
################################################################################

cmake_minimum_required( VERSION 3.12 )
project( _cpp_root_project_ LANGUAGES C CXX )

# ////////////////////////////////////////////////////////////////////////////////
# LANGUAGE STANDARDS
# ////////////////////////////////////////////////////////////////////////////////

set( CMAKE_C_STANDARD 99 CACHE STRING "C compiler standard" )
set_property( CACHE CMAKE_C_STANDARD PROPERTY STRINGS 99 )
message( "Using C compiler standard --std=c${CMAKE_C_STANDARD}" )

set( CMAKE_CXX_STANDARD 20 CACHE STRING "CXX compiler standard" )
set_property( CACHE CMAKE_CXX_STANDARD PROPERTY STRINGS 20 )
message( "Using CXX compiler standard --std=c++${CMAKE_CXX_STANDARD}" )

set( CMAKE_C_STANDARD_REQUIRED ON )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( CMAKE_C_EXTENSIONS OFF )
set( CMAKE_CXX_EXTENSIONS OFF )

# ////////////////////////////////////////////////////////////////////////////////
# BUILD TARGETS
# ////////////////////////////////////////////////////////////////////////////////

set_property( CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "Size-Optimized-Release" )
if( "${CMAKE_BUILD_TYPE}" STREQUAL "" )
	set( CMAKE_BUILD_TYPE "Debug" CACHE STRING "Project Configuration" FORCE )
endif()

if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug" )
	set( CMAKE_CXX_FLAGS "" )
	set( CMAKE_C_FLAGS "" )

	if ( ${CMAKE_C_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" )
		set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Og -g -Wall -Wextra -Wconversion -Wuninitialized -pedantic -pedantic-errors -fanalyzer " )
		set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Og -g -Wall -Wextra -Wconversion -Wuninitialized -pedantic -pedantic-errors -fanalyzer " )
	endif()

	if ( ${CMAKE_C_COMPILER_ID} MATCHES "Clang" OR ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang" )
		set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Og -g -Wall -Wextra -Wconversion -Wuninitialized -pedantic -pedantic-errors " )
		set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Og -g -Wall -Wextra -Wconversion -Wuninitialized -pedantic -pedantic-errors " )
	endif()

	if ( ${MSVC} )
		set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /Od /W4 " )
		set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Od /W4 " )
	endif()

elseif( "${CMAKE_BUILD_TYPE}" STREQUAL "Release" )
	set( CMAKE_CXX_FLAGS "" )
	set( CMAKE_C_FLAGS "" )

	if ( ${CMAKE_C_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" )
		set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -s " )
		set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -s " )
	endif()

	if ( ${CMAKE_C_COMPILER_ID} MATCHES "Clang" OR ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang" )
		set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -Wl,-s " )
		set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wl,-s " )
	endif()

	if ( ${MSVC} )
		set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /O2 " )
		set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /O2 " )
	endif()

	add_compile_definitions( NDEBUG )
elseif( "${CMAKE_BUILD_TYPE}" STREQUAL "Size-Optimized-Release" )
	set( CMAKE_CXX_FLAGS "" )
	set( CMAKE_C_FLAGS "" )

	if ( ${CMAKE_C_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" )
		set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Os -s " )
		set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -s " )
	endif()

	if ( ${CMAKE_C_COMPILER_ID} MATCHES "Clang" OR ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang" )
		set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Os -Wl,-s " )
		set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -Wl,-s " )
	endif()

	if ( ${MSVC} )
		set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /O1 " )
		set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /O1 " )
	endif()

	add_compile_definitions( NDEBUG )
endif()

message( "Using compiler flags: ${CMAKE_CXX_FLAGS}" )
message( "Building project '${CMAKE_BUILD_TYPE}' configuration" )

# ////////////////////////////////////////////////////////////////////////////////
# INDIVIDUAL OUTPUT EXECUTABLES
# ////////////////////////////////////////////////////////////////////////////////

# Output executable: _cpp_base_executable_
set( _cpp_base_executable__SOURCES
	${PROJECT_SOURCE_DIR}/main.cpp
)

set( _cpp_base_executable__INCLUDE_DIRS
	${PROJECT_SOURCE_DIR}/include
)

add_executable( _cpp_base_executable_ ${_cpp_base_executable__SOURCES} )
target_include_directories( _cpp_base_executable_ PRIVATE ${_cpp_base_executable__INCLUDE_DIRS} )

set_target_properties( _cpp_base_executable_ PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}
)

