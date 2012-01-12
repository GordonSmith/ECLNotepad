find_path(	SCITE_INCLUDE_DIR src/SciTE.h
			HINTS ${SCITE_DIR}
			PATH_SUFFIXES src
			)

set(SCITE_INCLUDE_DIRS ${SCITE_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SCITE DEFAULT_MSG
                                  SCITE_INCLUDE_DIR)

