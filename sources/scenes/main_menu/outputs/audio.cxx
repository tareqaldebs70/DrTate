///////////////////////////////////
/// main_menu/outputs/audio.cxx ///
///////////////////////////////////




////////////////
/// Includes ///
////////////////

///////////////////////////////////////////
#include"scenes/main_menu/main_menu.hxx"///
///////////////////////////////////////////




using namespace Game;
using namespace Scenes;




/////////////////////
/// playing Audio ///
/////////////////////

////////////////////////////////////////////////////////////////////////
void MainMenu::playAudio(void)                                       ///
{                                                                    ///
    if(this->m_selected_changed == true)                             ///
    {                                                                ///
        Mix_PlayChannel(-1,ResourceManager::g_SoundList["select"],0);///
        this->m_selected_changed = false;                            ///
    }                                                                ///
    if(!Mix_PlayingMusic())                                          ///
    {                                                                ///
        Mix_PlayMusic(                                               ///
            ResourceManager::g_MusicList["main_menu"],               ///
            0                                                        ///
        );                                                           ///
    }                                                                ///
}                                                                    ///
////////////////////////////////////////////////////////////////////////