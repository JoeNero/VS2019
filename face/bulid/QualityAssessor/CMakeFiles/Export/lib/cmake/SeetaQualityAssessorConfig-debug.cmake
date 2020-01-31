#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SeetaFace::SeetaQualityAssessor" for configuration "Debug"
set_property(TARGET SeetaFace::SeetaQualityAssessor APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SeetaFace::SeetaQualityAssessor PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/SeetaQualityAssessor-d.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/SeetaQualityAssessor-d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SeetaFace::SeetaQualityAssessor )
list(APPEND _IMPORT_CHECK_FILES_FOR_SeetaFace::SeetaQualityAssessor "${_IMPORT_PREFIX}/lib/SeetaQualityAssessor-d.lib" "${_IMPORT_PREFIX}/bin/SeetaQualityAssessor-d.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
