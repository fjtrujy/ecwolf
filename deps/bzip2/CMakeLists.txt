cmake_minimum_required( VERSION 2.8.12 )

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC" )

if(POLICY CMP0054)
	cmake_policy(SET CMP0054 NEW)
endif()

if( "${CMAKE_C_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_C_COMPILER_ID}" STREQUAL "Clang" )
	set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -fomit-frame-pointer" )
endif()

add_definitions( -DBZ_NO_STDIO )
add_library( bz2 STATIC
    blocksort.c
    bzlib.c
    compress.c
    crctable.c
    decompress.c
    huffman.c
    randtable.c )
target_link_libraries( bz2 )
