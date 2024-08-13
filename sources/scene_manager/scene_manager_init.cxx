//////////////////////////////
/// scene_manager_init.cxx ///
//////////////////////////////




////////////////
/// Includes ///
////////////////

///////////////////////////////////////////////////
#include"scene_manager/scene_manager.hxx"	    ///
#include"scenes/main_menu/main_menu.hxx" 	    ///
#include"scenes/settings_menu/settings_menu.hxx"///
#include<SDL2/SDL.h>                     	    ///
///////////////////////////////////////////////////




using namespace Game;




//////////////////////////////////////////////////////////
/// Initializing stuff that makes this class singleton ///
//////////////////////////////////////////////////////////

///////////////////////////////////////////////////
SceneManager* SceneManager::pInstance = nullptr;///
SceneManager* SceneManager::getInstance(void)   ///
{                                               ///
    if(pInstance==nullptr)                      ///
    {                                           ///
        pInstance = new SceneManager;           ///
    }                                           ///
    return pInstance;                           ///
}                                               ///
void SceneManager::releaseInstance(void)        ///
{                                               ///
    if(pInstance!=nullptr)                      ///
        delete pInstance;                       ///
}                                               ///
///////////////////////////////////////////////////



////////////////////////////////////////
/// load current scene if not loaded ///
////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
void SceneManager::init(SDL_Window* pWindow,SDL_Renderer* pRenderer) ///
{                                                                    ///
    //////////////////////////////////                               ///
    /// First Scene to be selected ///                               ///
    //////////////////////////////////                               ///
///                                                                  ///
    ///////////////////////////////////////////////                  ///
    /// @brief first scene to load              ///                  ///
    if(Global::selectedScene==NULL_SCENE)       ///                  ///
        Global::selectedScene = MAIN_MENU_SCENE;///                  ///
    ///////////////////////////////////////////////                  ///
///                                                                  ///
///                                                                  ///
///                                                                  ///
///                                                                  ///
    if(this->m_CurrentScene != Global::selectedScene)                ///
    {                                                                ///
        switch(Global::selectedScene)                                ///
        {                                                            ///
            case MAIN_MENU_SCENE:                                    ///
                this->m_CurrentScene = MAIN_MENU_SCENE;              ///
                if(this->m_pCurrentScene!=nullptr)                   ///
                {                                                    ///
                    this->m_pCurrentScene->exit(pWindow);            ///
                    delete this->m_pCurrentScene;                    ///
                }                                                    ///
                this->m_pCurrentScene = new Scenes::MainMenu;        ///
                m_pCurrentScene->init(pWindow,pRenderer);            ///
///                                                                  ///
                break;                                               ///
	    case SETTINGS_MENU_SCENE:                                    ///
		    this->m_CurrentScene = SETTINGS_MENU_SCENE;              ///
    		    if(this->m_pCurrentScene!=nullptr)                   ///
		    {                                                        ///
			    this->m_pCurrentScene->exit(pWindow);                ///
			    delete this->m_pCurrentScene;                        ///
		    }                                                        ///
		    this->m_pCurrentScene = new Scenes::SettingsMenu;        ///
		    this->m_pCurrentScene->init(pWindow,pRenderer);          ///
		    break;                                                   ///
            default:                                                 ///
                break;                                               ///
        }                                                            ///
    }                                                                ///
}                                                                    ///
////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////
/// whene program stops exit last scene and clean it ///
////////////////////////////////////////////////////////

////////////////////////////////////////////////
void SceneManager::exit(SDL_Window* pWindow) ///
{                                            ///
    if(this->m_pCurrentScene!=nullptr)       ///
    {                                        ///
        this->m_pCurrentScene->exit(pWindow);///
    }                                        ///
}                                            ///
////////////////////////////////////////////////




///////////////////////////////////////////
/// handle current scene keyboard input ///
///////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
void SceneManager::whenKeyboardKeyIsPressed(SDL_Window* pWindow, SDL_Event* pEvent) ///
{                                                                                   ///
    if(this->m_pCurrentScene!=nullptr)                                              ///
        this->m_pCurrentScene->whenKeyboardKeyIsPressed(pWindow,pEvent);            ///
}                                                                                   ///
void SceneManager::whenKeyboardKeyIsReleased(SDL_Window* pWindow, SDL_Event* pEvent)///
{                                                                                   ///
    if(this->m_pCurrentScene!=nullptr)                                              ///
        this->m_pCurrentScene->whenKeyboardKeyIsReleased(pWindow,pEvent);           ///
}                                                                                   ///
///////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////
/// handle current scene mouse input ///
////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
void SceneManager::whenMouseButtonIsPressed (SDL_Window* pWindow, SDL_Event* pEvent)///
{                                                                                   ///
    if(this->m_pCurrentScene!=nullptr)                                              ///
        this->m_pCurrentScene->whenMouseButtonIsPressed(pWindow,pEvent);            ///
}                                                                                   ///
void SceneManager::whenMouseButtonIsReleased(SDL_Window* pWindow, SDL_Event* pEvent)///
{                                                                                   ///
    if(this->m_pCurrentScene!=nullptr)                                              ///
        this->m_pCurrentScene->whenMouseButtonIsReleased(pWindow,pEvent);           ///
}                                                                                   ///
void SceneManager::whenMouseMoves(SDL_Window* pWindow, SDL_Event* pEvent)           ///
{                                                                                   ///
    if(this->m_pCurrentScene!=nullptr)                                              ///
        this->m_pCurrentScene->whenMouseMoves(pWindow,pEvent);                      ///
}                                                                                   ///
void SceneManager::whenMouseWheelIsRolled(SDL_Window* pWindow, SDL_Event* pEvent)   ///
{                                                                                   ///
    if(this->m_pCurrentScene!=nullptr)                                              ///
        this->m_pCurrentScene->whenMouseWheelIsRolled(pWindow,pEvent);              ///
}                                                                                   ///
///////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////
/// updating current scene simulation ///
/////////////////////////////////////////

//////////////////////////////////////////////////////////////
/// @brief updating physics, animation and movement        ///
void SceneManager::updateSimulation(uint64_t deltaTime)    ///                          
{                                                          ///
    if(this->m_pCurrentScene!=nullptr)                     ///
        this->m_pCurrentScene->updateSimulation(deltaTime);///
}                                                          ///
//////////////////////////////////////////////////////////////




////////////////////////////////////
/// playing currents scene audio ///
////////////////////////////////////

//////////////////////////////////////////////
void SceneManager::playAudio(void)         ///
{                                          ///
    if(this->m_pCurrentScene!=nullptr)     ///
        this->m_pCurrentScene->playAudio();///
}                                          ///
//////////////////////////////////////////////




////////////////////////////////
/// Rendering scene graphics ///
////////////////////////////////

/////////////////////////////////////////////////////////////
void SceneManager::renderGraphics(SDL_Renderer* pRenderer)///
{                                                         ///
    if(this->m_pCurrentScene!=nullptr)                    ///
        this->m_pCurrentScene->renderGraphics(pRenderer); ///
}                                                         ///
/////////////////////////////////////////////////////////////
