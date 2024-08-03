//////////////////////////////
/// scene_manager_init.cxx ///
//////////////////////////////




////////////////
/// Includes ///
////////////////

////////////////////////////////////////////
#include"scene_manager/scene_manager.hxx"///
////////////////////////////////////////////




using namespace Game;




SceneManager* SceneManager::pInstance = nullptr;




SceneManager* SceneManager::getInstance(void)
{
    if(pInstance==nullptr)
    {
        pInstance = new SceneManager;
    }
    return pInstance;
}




void SceneManager::releaseInstance(void)
{
    if(pInstance!=nullptr)
        delete pInstance;
}




void SceneManager::init(SDL_Window* pWindow,SDL_Renderer* pRenderer)
{
    if(this->m_CurrentScene != Global::selectedScene)
    {
        switch(Global::selectedScene)
        {
            case MAIN_MENU_SCENE:
                break;
            default:
                break;
        }
    }
}




void SceneManager::exit(SDL_Window* pWindow)
{
    if(this->m_pCurrentScene!=nullptr)
    {
        this->m_pCurrentScene->exit(pWindow);
    }
}




void SceneManager::whenKeyboardKeyIsPressed(SDL_Window* pWindow, SDL_Event* pEvent)
{
    if(this->m_pCurrentScene!=nullptr)
        this->m_pCurrentScene->whenKeyboardKeyIsPressed(pWindow,pEvent);
}
void SceneManager::whenKeyboardKeyIsReleased(SDL_Window* pWindow, SDL_Event* pEvent)
{
    if(this->m_pCurrentScene!=nullptr)
        this->m_pCurrentScene->whenKeyboardKeyIsReleased(pWindow,pEvent);
}
void SceneManager::whenMouseButtonIsPressed (SDL_Window* pWindow, SDL_Event* pEvent)
{
    if(this->m_pCurrentScene!=nullptr)
        this->m_pCurrentScene->whenMouseButtonIsPressed(pWindow,pEvent);
}
void SceneManager::whenMouseButtonIsReleased(SDL_Window* pWindow, SDL_Event* pEvent)
{
    if(this->m_pCurrentScene!=nullptr)
        this->m_pCurrentScene->whenMouseButtonIsReleased(pWindow,pEvent);
}
void SceneManager::whenMouseMoves(SDL_Window* pWindow, SDL_Event* pEvent)
{
    if(this->m_pCurrentScene!=nullptr)
        this->m_pCurrentScene->whenMouseMoves(pWindow,pEvent);
}
void SceneManager::whenMouseWheelIsRolled(SDL_Window* pWindow, SDL_Event* pEvent)
{
    if(this->m_pCurrentScene!=nullptr)
        this->m_pCurrentScene->whenMouseWheelIsRolled(pWindow,pEvent);
}
void SceneManager::updateSimulation(uint64_t deltaTime)
{
    if(this->m_pCurrentScene!=nullptr)
        this->m_pCurrentScene->updateSimulation(deltaTime);
}
void SceneManager::playAudio(void)
{
    if(this->m_pCurrentScene!=nullptr)
        this->m_pCurrentScene->playAudio();
}
void SceneManager::renderGraphics(SDL_Renderer* pRenderer)
{
    if(this->m_pCurrentScene!=nullptr)
        this->m_pCurrentScene->renderGraphics(pRenderer);
}
