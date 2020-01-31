#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SeetaFace::SeetaFaceTracker" for configuration "Debug"
set_property(TARGET SeetaFace::SeetaFaceTracker APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SeetaFace::SeetaFaceTracker PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/SeetaFaceTracker-d.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "SeetaFace::SeetaFaceDetector"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/SeetaFaceTracker-d.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS SeetaFace::SeetaFaceTracker )
list(APPEND _IMPORT_CHECK_FILES_FOR_SeetaFace::SeetaFaceTracker "${_IMPORT_PREFIX}/lib/SeetaFaceTracker-d.lib" "${_IMPORT_PREFIX}/bin/SeetaFaceTracker-d.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)