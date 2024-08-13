//////////////////////////////////////
/// main_menu/outputs/grahpics.cxx ///
//////////////////////////////////////




////////////////
/// Includes ///
////////////////

///////////////////////////////////////////
#include"scenes/main_menu/main_menu.hxx"///
///////////////////////////////////////////




using namespace Game;
using namespace Scenes;




////////////////////////////////
/// rendering scene graphics ///
////////////////////////////////

////////////////////////////////////////////////////////////////////////
void MainMenu::renderGraphics(SDL_Renderer* pRenderer)               ///
{                                                                    ///
    SDL_RenderCopy(                                                  ///
        pRenderer,                                                   ///
        ResourceManager::g_TexturesList["main_menu_background"],     ///
        NULL,                                                        ///
        NULL                                                         ///
    );                                                               ///
    /// This switch simply determine where to  draw                  ///
    /// the cursor that point to the selected option from            ///
    // the main menu                                                 ///
    switch(this->m_choice)                                           ///
    {                                                                ///
        case 0x0: // play                                            ///
            this->m_selected_dest_rect.y = 192;                      ///
            break;                                                   ///
        case 0x1: // Load                                            ///
            this->m_selected_dest_rect.y  = 224;                     ///
            break;                                                   ///
        case 0x2: // Options                                         ///
            this->m_selected_dest_rect.y = 256;                      ///
            break;                                                   ///
        case 0x3: // quit                                            ///
            this->m_selected_dest_rect.y = 288;                      ///
            break;                                                   ///
        default:                                                     ///
            break;                                                   ///
    }                                                                ///
    SDL_RenderCopy(                                                  ///
        pRenderer,                                                   ///
        ResourceManager::g_TexturesList["main_menu_selected"],       ///
        NULL,                                                        ///
        &this->m_selected_dest_rect                                  ///
    );                                                               ///
    SDL_RenderCopy(                                                  ///
        pRenderer,                                                   ///
        ResourceManager::g_TexturesList["project_info"],             ///
        NULL,                                                        ///
        &this->m_project_info_rect                                   ///
    );                                                               ///
}                                                                    ///
////////////////////////////////////////////////////////////////////////