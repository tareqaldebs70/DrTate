//////////////////////////
/// main_menu/exit.cxx ///
//////////////////////////




////////////////
/// Includes ///
////////////////

///////////////////////////////////////////
#include"scenes/main_menu/main_menu.hxx"///
///////////////////////////////////////////




using namespace Game;
using namespace Scenes;




///////////////////////////////////////////////////
/// when exiting from scene clean some textures ///
///////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
void MainMenu::exit(SDL_Window* pWindow)                        ///
{                                                               ///
    ////////                                                    ///
    SDL_DestroyTexture(                                         ///
        ResourceManager::g_TexturesList["main_menu_background"] ///
    );                                                          ///
    SDL_DestroyTexture(                                         ///
        ResourceManager::g_TexturesList["main_menu_selected"]   ///
    );                                                          ///
    SDL_DestroyTexture(                                         ///
        ResourceManager::g_TexturesList["project_info"]         ///
    );                                                          ///
    Mix_FreeChunk(ResourceManager::g_SoundList["select"]);      ///
}                                                               ///
///////////////////////////////////////////////////////////////////