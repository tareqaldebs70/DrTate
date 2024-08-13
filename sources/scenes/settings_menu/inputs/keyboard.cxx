/////////////////////////////////////////
/// settings_menu/inputs/keyboard.cxx ///
/////////////////////////////////////////




////////////////
/// Includes ///
////////////////

///////////////////////////////////////////////////
#include"scenes/settings_menu/settings_menu.hxx"///
///////////////////////////////////////////////////




using namespace Game;
using namespace Scenes;




/////////////////////////////////////////////////
/// when keyboard key is pressed do something ///
/////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////
void SettingsMenu::whenKeyboardKeyIsPressed(SDL_Window* pWindow,SDL_Event* pEvent)                  ///
{                                                                                                   ///
    this->m_key_state = SDL_GetKeyboardState(NULL);                                                 ///
    if(this->m_key_state[SDL_SCANCODE_UP]==1)                                                       ///
    {                                                                                               ///
        this->m_selected_changed = true;                                                            ///
        if(this->m_choice==0)                                                                       ///
        {                                                                                           ///
            this->m_choice = 3;                                                                     ///
        }                                                                                           ///
        else                                                                                        ///
        {                                                                                           ///
            this->m_choice--;                                                                       ///
        }                                                                                           ///
    }                                                                                               ///
    if(this->m_key_state[SDL_SCANCODE_DOWN]==1)                                                     ///
    {                                                                                               ///
        this->m_selected_changed = true;                                                            ///
        if(this->m_choice==3)                                                                       ///
        {                                                                                           ///
            this->m_choice = 0;                                                                     ///
        }                                                                                           ///
        else                                                                                        ///
        {                                                                                           ///
            this->m_choice++;                                                                       ///
        }                                                                                           ///
    }                                                                                               ///
    if(this->m_key_state[SDL_SCANCODE_RIGHT]==1)                                                    ///
    {                                                                                               ///
        switch(this->m_choice)                                                                      ///
        {                                                                                           ///
            case 0: // if the master volume is selected                                             ///
                if(Global::master_volume != MIX_MAX_VOLUME) // if master volume not max increase it ///
                {                                                                                   ///
                    Global::master_volume += 16;                                                    ///
                    Global::saveSettings();                                                         ///
                    Mix_MasterVolume(static_cast<int>(Global::master_volume));                      ///
                }                                                                                   ///
                break;                                                                              ///
            case 1: // if the sfx volume is selected                                                ///
                if(Global::sfx_volume != MIX_MAX_VOLUME)                                            ///
                {                                                                                   ///
                    Global::sfx_volume += 16;                                                       ///
                    Global::saveSettings();                                                         ///
                    Mix_Volume(-1,static_cast<int>(Global::sfx_volume));                            ///
                }                                                                                   ///
                break;                                                                              ///
            case 2: // if the music volume is selected                                              ///
                if(Global::music_volume != MIX_MAX_VOLUME)                                          ///
                {                                                                                   ///
                    Global::music_volume += 16;                                                     ///
                    Global::saveSettings();                                                         ///
                    Mix_VolumeMusic(static_cast<int>(Global::music_volume));                        ///
                }                                                                                   ///
                break;                                                                              ///
            default:                                                                                ///
                break;                                                                              ///
        }                                                                                           ///
    }                                                                                               ///
    if(this->m_key_state[SDL_SCANCODE_LEFT]==1)                                                     ///
    {                                                                                               ///
        switch(this->m_choice)                                                                      ///
        {                                                                                           ///
            case 0: // if the master volume is selected                                             ///
                if(Global::master_volume != 0) // if master volume not max increase it              ///
                {                                                                                   ///
                    Global::master_volume -= 16;                                                    ///
                    Global::saveSettings();                                                         ///
                    Mix_MasterVolume(static_cast<int>(Global::master_volume));                      ///
                }                                                                                   ///
                break;                                                                              ///
            case 1: // if the sfx volume is selected                                                ///
                if(Global::sfx_volume != 0)                                                         ///
                {                                                                                   ///
                    Global::sfx_volume -= 16;                                                       ///
                    Global::saveSettings();                                                         ///
                    Mix_Volume(-1,static_cast<int>(Global::sfx_volume));                            ///
                }                                                                                   ///
                break;                                                                              ///
            case 2: // if the music volume is selected                                              ///
                if(Global::music_volume != 0)                                                       ///
                {                                                                                   ///
                    Global::music_volume -= 16;                                                     ///
                    Global::saveSettings();                                                         ///
                    Mix_VolumeMusic(static_cast<int>(Global::music_volume));                        ///
                }                                                                                   ///
                break;                                                                              ///
            default:                                                                                ///
                break;                                                                              ///
        }                                                                                           ///
    }                                                                                               ///
}                                                                                                   ///
///////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////
/// when keyboard key is released do something ///
//////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
void SettingsMenu::whenKeyboardKeyIsReleased(SDL_Window* pWindow,SDL_Event* pEvent)///
{                                                                                  ///
    switch(pEvent->key.keysym.sym)                                                 ///
    {                                                                              ///
        case SDLK_RETURN:                                                          ///
            if(this->m_choice==3)                                                  ///
            {Global::selectedScene = MAIN_MENU_SCENE;}                             ///
            break;                                                                 ///
        case SDLK_F11:                                                             ///
            if(!Global::windowed)                                                  ///
            {                                                                      ///
                Global::windowed = true;                                           ///
                SDL_SetWindowFullscreen(pWindow,0);                                ///
            }                                                                      ///
            else                                                                   ///
            {                                                                      ///
                Global::windowed = false;                                          ///
		        SDL_SetWindowFullscreen(pWindow,SDL_WINDOW_FULLSCREEN);            ///
            }                                                                      ///
            Global::saveSettings();                                                ///
            break;                                                                 ///
        default:                                                                   ///
            break;                                                                 ///
    }                                                                              ///
}                                                                                  ///
//////////////////////////////////////////////////////////////////////////////////////