cmake_minimum_required(VERSION 3.30.0)

project(DoctorTate VERSION 0.0.0.1)

set(PROJECT_STATE pre-alpha)

file(
    COPY        ${PROJECT_SOURCE_DIR}/assets
    DESTINATION ${PROJECT_BINARY_DIR}
)

# searching for sdl2 
find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/sources/main/main.cxx
    ${PROJECT_SOURCE_DIR}/sources/core/core_init.cxx
    ${PROJECT_SOURCE_DIR}/sources/core/core_run.cxx
    ${PROJECT_SOURCE_DIR}/sources/global/global_window.cxx
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
configure_file(
    ${PROJECT_SOURCE_DIR}/includes/global/global.hxx.in
    ${PROJECT_SOURCE_DIR}/includes/global/global.hxx
)
# /////////////////////////

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_BINARY_DIR}
    ${PROJECT_SOURCE_DIR}/includes
    ${SDL2_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    ${SDL2_LIBRARIES}
)
