project(generic)

aux_source_directory(${PROJECT_SOURCE_DIR} GENERIC_FILES)

include_directories(${GENERIC_DIR}/include)

add_library(${PROJECT_NAME} STATIC ${GENERIC_FILES})



