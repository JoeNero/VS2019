#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SeetaFace::SeetaNet" for configuration "RelWithDebInfo"
set_property(TARGET SeetaFace::SeetaNet APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(SeetaFace::SeetaNet PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/SeetaNet.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELWITHDEBINFO "Ws2_32"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/SeetaNet.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SeetaFace::SeetaNet )
list(APPEND _IMPORT_CHECK_FILES_FOR_SeetaFace::SeetaNet "${_IMPORT_PREFIX}/lib/SeetaNet.lib" "${_IMPORT_PREFIX}/bin/SeetaNet.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
