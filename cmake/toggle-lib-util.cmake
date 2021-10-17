function( make_toggle_lib
  lib_name
  default_lib_type
  lib_entry_file
  lib_sources
  lib_headers
  lib_template_impls
)
  if (NOT "${default_lib_type}" STREQUAL "STATIC" AND NOT "${default_lib_type}" STREQUAL "SHARED")
    message( FATAL_ERROR "Invalid default lib type '${default_lib_type}' given to type toggleable library ${lib_name}" )
  endif()

  if( NOT ${lib_name}_LIB_TYPE )
    set( ${lib_name}_LIB_TYPE ${default_lib_type} CACHE STRING "Library type for ${lib_name}" )
  endif()

  set_property( CACHE ${lib_name}_LIB_TYPE PROPERTY STRINGS "STATIC" "SHARED" )

  set( all_lib_files ${lib_entry_file} ${lib_sources} ${lib_headers} ${lib_template_impls} )

  if ( ${lib_name}_LIB_TYPE STREQUAL STATIC )
    add_library( ${lib_name} STATIC ${all_lib_files})
  elseif( ${lib_name}_LIB_TYPE STREQUAL SHARED )
    add_library( ${lib_name} SHARED ${all_lib_files})
  endif()
endfunction()
