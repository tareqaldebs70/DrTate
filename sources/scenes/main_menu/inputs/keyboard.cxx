/////////////////////////////////////
/// main_menu/inputs/keyboard.cxx ///
/////////////////////////////////////




////////////////
/// Inlcudes ///
////////////////

///////////////////////////////////////////
#include"scenes/main_menu/main_menu.hxx"///
#include"scene_manager/scenes_list.hxx" ///
#include<iostream>// for debugging      ///
///////////////////////////////////////////




using namespace Game;
using namespace Scenes;



/////////////////////////////////////////////////
/// when keyboard key is pressed do something ///
/////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
void MainMenu::whenKeyboardKeyIsPressed(SDL_Window* pWindow, SDL_Event* pEvent)///
{                                                                              ///
    this->m_key_state = SDL_GetKeyboardState(NULL);                            ///
    if(this->m_key_state[SDL_SCANCODE_UP]==1)                                  ///
    {                                                                          ///
        if(this->m_selected_changed == false)                                  ///
            this->m_selected_changed = true;                                   ///
        if(this->m_choice==0)                                                  ///
        {                                                                      ///
            this->m_choice = 3;                                                ///
        }                                                                      ///
        else                                                                   ///
        {                                                                      ///
            m_choice--;                                                        ///
        }                                                                      ///
    }                                                                          ///
    if(this->m_key_state[SDL_SCANCODE_DOWN]==1)                                ///
    {                                                                          ///
        if(this->m_selected_changed == false)                                  ///
            this->m_selected_changed = true;                                   ///
        if(this->m_choice==3)                                                  ///
        {                                                                      ///
            this->m_choice = 0;                                                ///
        }                                                                      ///
        else                                                                   ///
        {                                                                      ///
            this->m_choice++;                                                  ///
        }                                                                      ///
    }                                                                          ///
}                                                                              ///
//////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////
/// when keyboard key is released do sometihng ///
//////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
void MainMenu::whenKeyboardKeyIsReleased(SDL_Window* pWindow, SDL_Event* pEvent)///
{                                                                               ///
    switch(pEvent->key.keysym.sym)                                              ///
    {                                                                           ///
        case SDLK_RETURN:                                                       ///
            switch(this->m_choice)                                              ///
            {                                                                   ///
                case 0: // play choice selected and enter pressed               ///
                    // play game                                                ///
                    break;                                                      ///
                case 1: // load choice selected and...                          ///
                    // load save or something                                   ///
                    break;                                                      ///
                case 2: // options choice and ...                               ///
                    /// user will be taken to settings                          ///
                    Global::selectedScene = SETTINGS_MENU_SCENE;                ///
                    break;                                                      ///
                case 3: // will quit                                            ///
                    Global::isWindowRunning = false;                            ///
                    break;                                                      ///
                default:                                                        ///
                    break;                                                      ///
            }                                                                   ///
            break;                                                              ///
        case SDLK_F11:                                                          ///
            if(!Global::windowed)                                               ///
            {                                                                   ///
                Global::windowed = true;                                        ///
                SDL_SetWindowFullscreen(pWindow,0);                             ///
            }                                                                   ///
            else                                                                ///
            {                                                                   ///
                Global::windowed = false;                                       ///
		        SDL_SetWindowFullscreen(pWindow,SDL_WINDOW_FULLSCREEN);         ///
            }                                                                   ///
            Global::saveSettings();                                             ///
            break;                                                              ///
        default:                                                                ///
            break;                                                              ///
    }                                                                           ///
}                                                                               ///
///////////////////////////////////////////////////////////////////////////////////