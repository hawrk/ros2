#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "service_interface_ws::service_interface_ws__rosidl_typesupport_fastrtps_c" for configuration ""
set_property(TARGET service_interface_ws::service_interface_ws__rosidl_typesupport_fastrtps_c APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(service_interface_ws::service_interface_ws__rosidl_typesupport_fastrtps_c PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libservice_interface_ws__rosidl_typesupport_fastrtps_c.so"
  IMPORTED_SONAME_NOCONFIG "libservice_interface_ws__rosidl_typesupport_fastrtps_c.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS service_interface_ws::service_interface_ws__rosidl_typesupport_fastrtps_c )
list(APPEND _IMPORT_CHECK_FILES_FOR_service_interface_ws::service_interface_ws__rosidl_typesupport_fastrtps_c "${_IMPORT_PREFIX}/lib/libservice_interface_ws__rosidl_typesupport_fastrtps_c.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)