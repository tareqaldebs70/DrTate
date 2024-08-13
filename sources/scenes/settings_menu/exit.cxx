//////////////////////////////
/// settings_menu/exit.cxx ///
//////////////////////////////




////////////////
/// Includes ///
////////////////

///////////////////////////////////////////////////
#include"scenes/settings_menu/settings_menu.hxx"///
///////////////////////////////////////////////////




using namespace Game;
using namespace Scenes;




////////////////////////////////////////////////
/// when exiting from scene clean some stuff ///
////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
void SettingsMenu::exit(SDL_Window* pWindow)                        ///
{                                                                   ///
    Mix_FreeChunk(                                                  ///
        ResourceManager::g_SoundList["select"]                      ///
    );                                                              ///
    SDL_DestroyTexture(                                             ///
        ResourceManager::g_TexturesList["settings_menu_background"] ///
    );                                                              ///
    SDL_DestroyTexture(                                             ///
        ResourceManager::g_TexturesList["volume"]                   ///
    );                                                              ///
    SDL_DestroyTexture(                                             ///
        ResourceManager::g_TexturesList["select"]                   ///
    );                                                              ///
}                                                                   ///
///////////////////////////////////////////////////////////////////////