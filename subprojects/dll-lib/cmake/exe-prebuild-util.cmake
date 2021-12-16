function( use_executable_prebuild_script
  target_name
)
  add_custom_target( ${PROJECT_NAME}-pre-build-step
    ALL
    COMMAND ${target_name}
    DEPENDS ${target_name}
    COMMENT "Running ${PROJECT_NAME} pre-build script"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )
endfunction()
