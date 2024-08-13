cmake_minimum_required(VERSION 3.30.0)

project(DoctorTate VERSION 0.0.0.1)

set(PROJECT_STATE pre-alpha)

file(
    COPY        ${PROJECT_SOURCE_DIR}/assets
    DESTINATION ${PROJECT_BINARY_DIR}
)
file(
    COPY        ${PROJECT_SOURCE_DIR}/settings.ini
    DESTINATION ${PROJECT_BINARY_DIR}
)



# searching for sdl2 
find_package(SDL2 REQUIRED)
find_package(SDL2_image)
find_package(SDL2_mixer)
find_package(SDL2_ttf)



add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/sources/main/main.cxx
    ${PROJECT_SOURCE_DIR}/sources/core/core_init.cxx
    ${PROJECT_SOURCE_DIR}/sources/core/core_run.cxx
    ${PROJECT_SOURCE_DIR}/sources/global/global_window.cxx
    ${PROJECT_SOURCE_DIR}/sources/global/global_scene_manager.cxx
    ${PROJECT_SOURCE_DIR}/sources/global/global_settings.cxx
    ${PROJECT_SOURCE_DIR}/sources/global/global_font.cxx
    ${PROJECT_SOURCE_DIR}/sources/scene_manager/scene_manager_init.cxx
    ${PROJECT_SOURCE_DIR}/sources/scenes/main_menu/init.cxx
    ${PROJECT_SOURCE_DIR}/sources/scenes/main_menu/exit.cxx
    ${PROJECT_SOURCE_DIR}/sources/scenes/main_menu/inputs/keyboard.cxx
    ${PROJECT_SOURCE_DIR}/sources/scenes/main_menu/inputs/mouse.cxx
    ${PROJECT_SOURCE_DIR}/sources/scenes/main_menu/update_simulation.cxx
    ${PROJECT_SOURCE_DIR}/sources/scenes/main_menu/outputs/audio.cxx
    ${PROJECT_SOURCE_DIR}/sources/scenes/main_menu/outputs/graphics.cxx
    ${PROJECT_SOURCE_DIR}/sources/resource_manager/resource_manager.cxx
    ${PROJECT_SOURCE_DIR}/sources/scenes/settings_menu/init.cxx
    ${PROJECT_SOURCE_DIR}/sources/scenes/settings_menu/exit.cxx
    ${PROJECT_SOURCE_DIR}/sources/scenes/settings_menu/inputs/keyboard.cxx
    ${PROJECT_SOURCE_DIR}/sources/scenes/settings_menu/inputs/mouse.cxx
    ${PROJECT_SOURCE_DIR}/sources/scenes/settings_menu/update_simulation.cxx
    ${PROJECT_SOURCE_DIR}/sources/scenes/settings_menu/outputs/audio.cxx
    ${PROJECT_SOURCE_DIR}/sources/scenes/settings_menu/outputs/graphics.cxx 
)

# //// configure files ////
configure_file(
    ${PROJECT_SOURCE_DIR}/includes/common/config.hxx
    ${PROJECT_BINARY_DIR}/includes/common/config.hxx
)
configure_file(
    ${PROJECT_SOURCE_DIR}/sources/main/main.hxx.in
    ${PROJECT_BINARY_DIR}/includes/main.hxx
)
configure_file(
    ${PROJECT_SOURCE_DIR}/includes/core/core.hxx
    ${PROJECT_BINARY_DIR}/includes/core/core.hxx
)
configure_file(
    ${PROJECT_SOURCE_DIR}/includes/global/global.hxx
    ${PROJECT_BINARY_DIR}/includes/global/global.hxx
)
configure_file(
    ${PROJECT_SOURCE_DIR}/includes/scenes/scene.hxx
    ${PROJECT_BINARY_DIR}/includes/scenes/scene.hxx
)
configure_file(
    ${PROJECT_SOURCE_DIR}/includes/scene_manager/scene_manager.hxx
    ${PROJECT_BINARY_DIR}/includes/scene_manager/scene_manager.hxx
)
configure_file(
    ${PROJECT_SOURCE_DIR}/includes/scene_manager/scenes_list.hxx
    ${PROJECT_BINARY_DIR}/includes/scene_manager/scenes_list.hxx
)
configure_file(
    ${PROJECT_SOURCE_DIR}/includes/scenes/main_menu/main_menu.hxx
    ${PROJECT_BINARY_DIR}/includes/scenes/main_menu/main_menu.hxx
)
configure_file(
    ${PROJECT_SOURCE_DIR}/includes/resource_manager/resource_manager.hxx
    ${PROJECT_BINARY_DIR}/includes/resource_manager/resource_manager.hxx
)
configure_file(
	${PROJECT_SOURCE_DIR}/includes/scenes/settings_menu/settings_menu.hxx
	${PROJECT_BINARY_DIR}/includes/scenes/settings_menu/settings_menu.hxx
)
# /////////////////////////

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_BINARY_DIR}/includes
    ${SDL2_INCLUDE_DIR}
    ${SDL2IMAGE_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    ${SDL2_LIBRARIES}
    SDL2_image::SDL2_image
    SDL2_mixer::SDL2_mixer
    SDL2_ttf::SDL2_ttf
)

