set(EXECUTABLE_OUTPUT_PATH bin)
file(GLOB INC_FILES ${CMAKE_CURRENT_LIST_DIR}/*.hpp)
file(GLOB SRC_FILES ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
add_executable(sample_03_adpter_pattern ${INC_FILES} ${SRC_FILES})

install(TARGETS sample_03_adpter_pattern RUNTIME DESTINATION bin)

