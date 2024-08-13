//////////////////////////
/// main_menu/init.cxx ///
//////////////////////////




////////////////
/// Includes ///
////////////////

///////////////////////////////////////////
#include"scenes/main_menu/main_menu.hxx"///
#include<iostream>                      ///
///////////////////////////////////////////




using namespace Game;
using namespace Scenes;




//////////////////////////
/// initializing scene ///
//////////////////////////

//////////////////////////////////////////////////////////////////////
void MainMenu::init(SDL_Window* pWindow,SDL_Renderer* pRenderer)   ///
{                                                                  ///
    Global::loadSettings();                                        ///
    SDL_RenderSetLogicalSize(                                      ///
        	pRenderer,                                             ///
        	Global::windowWidth,                                   ///
        	Global::windowHeight                                   ///
   	);                                                             ///
    if(!Global::windowed)	                                       ///
		SDL_SetWindowFullscreen(pWindow,SDL_WINDOW_FULLSCREEN);    ///
	else                                                           ///
		SDL_SetWindowFullscreen(pWindow,0);                        ///
    Mix_MasterVolume(static_cast<int>(Global::master_volume));     ///
	Mix_Volume(-1,static_cast<int>(Global::sfx_volume));           ///
	Mix_VolumeMusic(static_cast<int>(Global::music_volume));       ///
    if(!ResourceManager::g_TexturesList.empty())                   ///
    {                                                              ///
        ResourceManager::g_TexturesList.clear();                   ///
    }                                                              ///
    if(!ResourceManager::g_SoundList.empty())                      ///
    {                                                              ///
        ResourceManager::g_SoundList.clear();                      ///
    }                                                              ///
    ResourceManager::g_TexturesList["main_menu_background"]        ///
        = IMG_LoadTexture(                                         ///
        pRenderer,                                                 ///
        "assets/GFX/main_menu/Background.png"                      ///
    );                                                             ///
    ResourceManager::g_TexturesList["main_menu_selected"]          ///
        = IMG_LoadTexture(                                         ///
        pRenderer,                                                 ///
        "assets/GFX/main_menu/select.png"                          ///
    );                                                             ///
    ResourceManager::g_TexturesList["project_info"]                /// 
    = Global::writeProjectInfo(                                    ///
        pRenderer                                                  ///
    );                                                             ///
    this->m_project_info_rect.x  =  0*32;                          ///
    this->m_project_info_rect.y  = 14*32;                          ///
    this->m_project_info_rect.w  = 20*32;                          ///
    this->m_project_info_rect.h  =  1*32;                          ///
    this->m_selected_dest_rect.x =   160;                          ///
    this->m_selected_dest_rect.y =   192;                          ///
    this->m_selected_dest_rect.w =   288;                          ///
    this->m_selected_dest_rect.h =    32;                          ///
    /// loading sfx                                                ///
    ResourceManager::g_SoundList["select"]                         ///
        = Mix_LoadWAV("assets/SFX/select.wav");                    ///
    ResourceManager::g_MusicList["main_menu"]                      ///
        = Mix_LoadMUS("assets/SFX/MainMenu.wav");                  ///
}                                                                  ///
//////////////////////////////////////////////////////////////////////