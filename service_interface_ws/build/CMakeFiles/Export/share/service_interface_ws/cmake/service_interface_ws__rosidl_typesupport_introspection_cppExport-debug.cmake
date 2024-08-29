#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "service_interface_ws::service_interface_ws__rosidl_typesupport_introspection_cpp" for configuration "Debug"
set_property(TARGET service_interface_ws::service_interface_ws__rosidl_typesupport_introspection_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(service_interface_ws::service_interface_ws__rosidl_typesupport_introspection_cpp PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libservice_interface_ws__rosidl_typesupport_introspection_cpp.so"
  IMPORTED_SONAME_DEBUG "libservice_interface_ws__rosidl_typesupport_introspection_cpp.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS service_interface_ws::service_interface_ws__rosidl_typesupport_introspection_cpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_service_interface_ws::service_interface_ws__rosidl_typesupport_introspection_cpp "${_IMPORT_PREFIX}/lib/libservice_interface_ws__rosidl_typesupport_introspection_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
