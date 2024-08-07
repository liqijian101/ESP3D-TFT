# DO NOT EDIT THIS FILE
# Edit or Add target files in cmake/targets directory
#global drivers
set(EXTRA_COMPONENT_DIRS ${CMAKE_SOURCE_DIR}/hardware/drivers_common)

# all targets
file(GLOB TARGET_FILES "cmake/targets/*.cmake")
foreach(TARGET_FILE ${TARGET_FILES})
  include(${TARGET_FILE})
endforeach()