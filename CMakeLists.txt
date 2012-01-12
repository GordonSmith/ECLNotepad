project ( ECLNotepad )
cmake_minimum_required (VERSION 2.6)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/" ${CMAKE_MODULE_PATH})

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin" CACHE PATH "Location of BIN files")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/obj" CACHE PATH "Location of LIB files")

find_package(SCINTILLA REQUIRED)
find_package(SCITE REQUIRED)

add_definitions(-DNO_LUA)
if (WIN32)
	add_definitions(-D_UNICODE -DSTATIC_BUILD)
	if (MSVC)   
		add_definitions(-D_CRT_SECURE_NO_WARNINGS)
		foreach(flag_var
			CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO 
			CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO
			)
			if(${flag_var} MATCHES "/MD")
				string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
			endif()
		endforeach(flag_var)

		set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /MANIFEST:NO")
		set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /MANIFEST:NO")
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /MANIFEST:NO")
	endif()
elseif(APPLE)
elseif(UNIX)
	add_definitions(-DGTK)

	find_package(PkgConfig)
	# GTK is required for XEmbed to work
	if (NOT GTK_INCLUDE_DIRS)
		pkg_check_modules(GTK REQUIRED gtk+-2.0)
		set (GTK_INCLUDE_DIRS ${GTK_INCLUDE_DIRS} CACHE INTERNAL "GTK include dirs")
		set (GTK_LIBRARIES ${GTK_LIBRARIES} CACHE INTERNAL "GTK include dirs")
		set (GTK_LIBRARY_DIRS ${GTK_LIBRARY_DIRS} CACHE INTERNAL "GTK include dirs")
		set (GTK_LDFLAGS ${GTK_LDFLAGS} CACHE INTERNAL "GTK include dirs")
	endif()

endif()

add_subdirectory (ECLLexer)
add_subdirectory (ECLNotepad)
