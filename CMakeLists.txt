cmake_minimum_required(VERSION 3.30.0)

project(DoctorTate VERSION 0.0.0.1)


add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/sources/main/main.cxx
)

configure_file(
    ${PROJECT_SOURCE_DIR}/includes/common/config.h.in
    ${PROJECT_SOURCE_DIR}/includes/common/config.hxx
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/includes
)