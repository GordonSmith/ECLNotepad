project( ECLLexer ) 

# *********************************************************************

include_directories ( 
	${SCINTILLA_INCLUDE_DIR}/include
	${SCINTILLA_INCLUDE_DIR}/lexlib
	${SCINTILLA_INCLUDE_DIR}/src
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
	${SCINTILLA_INCLUDE_DIR}/src/[^.]*.h 
	${SCINTILLA_INCLUDE_DIR}/src/[^.]*.cxx

	${SCINTILLA_INCLUDE_DIR}/lexlib/[^.]*.h 
	${SCINTILLA_INCLUDE_DIR}/lexlib/[^.]*.cxx
	)

file (GLOB CATALOGUE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${SCINTILLA_INCLUDE_DIR}/src/Catalogue.*
    )

list(REMOVE_ITEM SRCS ${CATALOGUE_FILES})

# Lexers **************************************************************

file (GLOB LEX_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	${SCINTILLA_INCLUDE_DIR}/lexers/LexOthers.cxx

	#${SCINTILLA_INCLUDE_DIR}/lexers/[^.]*.h 
	#${SCINTILLA_INCLUDE_DIR}/lexers/[^.]*.cxx
	)
	
list(APPEND LEX_SRCS 
	LexECL.h
	LexECL.cxx
	)

SOURCE_GROUP(Lexers FILES ${LEX_SRCS})

# Win *****************************************************************

file (GLOB SRCS_WIN RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	${SCINTILLA_INCLUDE_DIR}/win32/[^.]*.h 
	${SCINTILLA_INCLUDE_DIR}/win32/[^.]*.cxx
	)

SOURCE_GROUP(Win FILES ${SRCS_WIN})

# OSX *****************************************************************

set (	SRCS_APPLE
	)

SOURCE_GROUP(OSX FILES ${SRCS_APPLE})

# X11 *****************************************************************

file (GLOB SRCS_UNIX RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	${SCINTILLA_INCLUDE_DIR}/gtk/[^.]*.h 
	${SCINTILLA_INCLUDE_DIR}/gtk/[^.]*.c
	${SCINTILLA_INCLUDE_DIR}/gtk/[^.]*.cxx
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

add_definitions(-DSCI_LEXER)

if(WIN32)
elseif(APPLE)
elseif(UNIX)
endif()

# *********************************************************************

set(SOURCES ${SRCS} ${LEX_SRCS} ${SRCS_WIN} ${SRCS_APPLE} ${SRCS_UNIX})
add_library(ECLLexer STATIC ${SOURCES})

# *********************************************************************

target_link_libraries ( ECLLexer 
	)

if(WIN32)
target_link_libraries ( ECLLexer 
	imm32.lib
	)
elseif(APPLE)
elseif(UNIX)
endif()

# *********************************************************************
