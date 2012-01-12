find_path(	SCINTILLA_INCLUDE_DIR src/Document.h
			HINTS ${SCINTILLA_DIR}
			PATH_SUFFIXES src
			)

set(SCINTILLA_INCLUDE_DIRS ${SCINTILLA_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SCINTILLA DEFAULT_MSG
                                  SCINTILLA_INCLUDE_DIR)

