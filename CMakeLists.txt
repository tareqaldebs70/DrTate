cmake_minimum_required(VERSION 3.30.0)

project(DoctorTate VERSION 0.0.0.1)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/sources/main/main.cxx
    ${PROJECT_SOURCE_DIR}/sources/core/core_init.cxx
    ${PROJECT_SOURCE_DIR}/sources/core/core_run.cxx
)

# //// configure files ////
configure_file(
    ${PROJECT_SOURCE_DIR}/includes/common/config.h.in
    ${PROJECT_SOURCE_DIR}/includes/common/config.hxx
)
configure_file(
    ${PROJECT_SOURCE_DIR}/sources/main/main.hxx.in
    ${PROJECT_SOURCE_DIR}/sources/main/main.hxx
)
configure_file(
    ${PROJECT_SOURCE_DIR}/includes/core/core.hxx.in
    ${PROJECT_SOURCE_DIR}/includes/core/core.hxx
)
# /////////////////////////

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/includes
)