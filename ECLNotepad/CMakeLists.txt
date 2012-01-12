project( ECLNotepad ) 

# *********************************************************************

include_directories ( 
	${SCINTILLA_INCLUDE_DIR}/include

	${SCITE_INCLUDE_DIR}/src
	)

if(WIN32)
elseif(APPLE)
elseif(UNIX)
	include_directories ( 
		${GTK_INCLUDE_DIRS}
		)
endif()

# *********************************************************************

file (GLOB SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	${SCITE_INCLUDE_DIR}/src/[^.]*.h 
	${SCITE_INCLUDE_DIR}/src/[^.]*.cxx
	)

file (GLOB LUA_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${SCITE_INCLUDE_DIR}/src/Lua*.*
    )

list(REMOVE_ITEM SRCS ${LUA_FILES})

# Win *****************************************************************

file (GLOB SRCS_WIN RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	${SCITE_INCLUDE_DIR}/win32/[^.]*.h 
	${SCITE_INCLUDE_DIR}/win32/[^.]*.cxx
	${SCITE_INCLUDE_DIR}/win32/[^.]*.rc
	)

SOURCE_GROUP(Win FILES ${SRCS_WIN})

# OSX *****************************************************************

set (	SRCS_APPLE
	)

SOURCE_GROUP(OSX FILES ${SRCS_APPLE})

# X11 *****************************************************************

file (GLOB SRCS_UNIX RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	${SCITE_INCLUDE_DIR}/gtk/[^.]*.h 
	${SCITE_INCLUDE_DIR}/gtk/[^.]*.c
	${SCITE_INCLUDE_DIR}/gtk/[^.]*.cxx
	)

SOURCE_GROUP(X11 FILES ${SRCS_UNIX})

# *********************************************************************

if(WIN32)
    set_source_files_properties(${SRCS_APPLE} PROPERTIES HEADER_FILE_ONLY 1)
    set_source_files_properties(${SRCS_UNIX} PROPERTIES HEADER_FILE_ONLY 1)
elseif(APPLE)
    set_source_files_properties(${SRCS_WIN} PROPERTIES HEADER_FILE_ONLY 1)
    set_source_files_properties(${SRCS_UNIX} PROPERTIES HEADER_FILE_ONLY 1)
elseif(UNIX)
    set_source_files_properties(${SRCS_WIN} PROPERTIES HEADER_FILE_ONLY 1)
    set_source_files_properties(${SRCS_APPLE} PROPERTIES HEADER_FILE_ONLY 1)
endif()

# *********************************************************************

add_definitions()

if(WIN32)
elseif(APPLE)
elseif(UNIX)
	add_definitions(-DPIXMAP_PATH="${SCITE_INCLUDE_DIR}/gtk")
endif()

# *********************************************************************

set(SOURCES ${SRCS} ${SRCS_WIN} ${SRCS_APPLE} ${SRCS_UNIX})
add_executable(ECLNotepad WIN32 ${SOURCES})

# *********************************************************************

target_link_libraries ( ECLNotepad 
	ECLLexer
	)

if(WIN32)
	target_link_libraries ( ECLNotepad 
		Msimg32.lib
		uxTheme.lib
		comctl32.lib
		)
elseif(APPLE)
elseif(UNIX)
	target_link_libraries ( ECLNotepad 
		${GTK_LIBRARIES}
		)
endif()

# *********************************************************************
