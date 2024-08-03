////////////////////
/// core_run.cxx ///
////////////////////




////////////////
/// Includes ///
////////////////

//////////////////////////////
#include"core/core.hxx"    ///
//////////////////////////////




using namespace Application;




/////////////////////////////////
/// This is our program heart ///
/////////////////////////////////

////////////////////////////////////////////////////////
void Core::run(void)
{




    /////////////////////////
    /// Initializing SDL  ///
    /////////////////////////
    
    ///////////////////////////////////////
    SDL_InitSubSystem(SDL_INIT_EVERYTHING);
	
    // making sure that these pointers
    // are clean
    this->m_pWindow   = nullptr;
    this->m_pRenderer = nullptr;

    this->m_pWindow = SDL_CreateWindow(
		    Global::windowTitle.c_str(),
		    SDL_WINDOWPOS_CENTERED,
		    SDL_WINDOWPOS_CENTERED,
		    Global::windowWidth,
            Global::windowHeight,
		    SDL_WINDOW_SHOWN 
		    );
    this->m_pRenderer = SDL_CreateRenderer(
		    this->m_pWindow,
		    -1,
		    SDL_RENDERER_ACCELERATED
		    );
    ///////////////////////////////////////




    ///////////////////////////
    /// Loading window icon ///
    ///////////////////////////

    /////////////////////////////////////////////////////////
    Global::windowIcon = SDL_LoadBMP("assets/icon.bmp");  ///
    SDL_SetWindowIcon(this->m_pWindow,Global::windowIcon);///
    /////////////////////////////////////////////////////////




    //////////////////////////////
    /// Starting scene Manager ///
    //////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    Game::SceneManager* m_pSceneManager = Game::SceneManager::getInstance();///
    ///////////////////////////////////////////////////////////////////////////




    //////////////////////////////
    /// Running the application///
    //////////////////////////////

    //////////////////////////////////////////////////
    while(Global::isWindowRunning)
    {




        ////////////////////////////////
        /// Load Scene if not loaded ///
        ////////////////////////////////

        ////////////////////////////////////////////////////////////
        m_pSceneManager->init(this->m_pWindow,this->m_pRenderer);///
        ////////////////////////////////////////////////////////////




        //////////////////////
        /// Handing events ///
        //////////////////////

        ////////////////////////////////////////////////////////////////////
	    SDL_Event event;                                                 ///
	    while(SDL_PollEvent(&event))                                     ///
	    {                                                                ///
		    switch(event.type)                                           ///
		    {                                                            ///
			    case SDL_QUIT:                                           ///
				    Global::isWindowRunning = false;                     ///
				    break;                                               ///
        ///                                                              ///
        ///                                                              ///
        ///                                                              ///
        ///                                                              ///
                /////////////////////////                                ///
                /// User input events ///                                ///
                /////////////////////////                                ///
        ///                                                              ///
                /////////////////////////////////////////////////        ///
                case SDL_KEYDOWN:                             ///        ///
                    m_pSceneManager->whenKeyboardKeyIsPressed(///        ///
                        this->m_pWindow,                      ///        ///
                        &event                                ///        ///
                    );                                        ///        ///
                    break;                                    ///        ///
                case SDL_KEYUP:                               ///        ///
                    m_pSceneManager->whenKeyboardKeyIsReleased///        ///
                    (this->m_pWindow,&event);                 ///        ///
                    break;                                    ///        ///
                case SDL_MOUSEBUTTONDOWN:                     ///        ///
                    m_pSceneManager->whenMouseButtonIsPressed(///        ///
                        this->m_pWindow,                      ///        ///
                        &event                                ///        ///
                    );                                        ///        ///
                    break;                                    ///        ///
                case SDL_MOUSEBUTTONUP:                       ///        ///
                    m_pSceneManager->whenMouseButtonIsReleased///        ///
                    (this->m_pWindow,&event);                 ///        ///
                    break;                                    ///        ///
                case SDL_MOUSEMOTION:                         ///        ///
                    m_pSceneManager->whenMouseMoves(          ///        ///
                        this->m_pWindow,                      ///        ///
                        &event                                ///        ///
                    );                                        ///        ///
                    break;                                    ///        ///
                case SDL_MOUSEWHEEL:                          ///        ///
                    m_pSceneManager->whenMouseWheelIsRolled(  ///        ///
                        this->m_pWindow,                      ///        ///
                        &event                                ///        ///
                    );                                        ///        ///
                    break;                                    ///        ///
                /////////////////////////////////////////////////        ///
        ///                                                              ///
        ///                                                              ///
        ///                                                              ///
        ///                                                              ///
			    default:                                                 ///
				    break;                                               ///
		    }                                                            ///
	    }                                                                ///
        ////////////////////////////////////////////////////////////////////




        //////////////////////////////////
        /// Updating scene simulation  ///
        //////////////////////////////////

        ///////////////////////////////////////////////////////
        m_pSceneManager->updateSimulation(SDL_GetTicks64());///
        ///////////////////////////////////////////////////////




        /////////////////////
        /// Playing audio ///
        /////////////////////

        ////////////////////////////////
        m_pSceneManager->playAudio();///
        ////////////////////////////////




        /////////////////
        /// Rendering ///
        /////////////////

        /////////////////////////////////////////////////
	    SDL_SetRenderDrawColor(                       ///
			    this->m_pRenderer,                    ///
			    0,0,0,255                             ///
			    );                                    ///
	    SDL_RenderClear  (this->m_pRenderer);         ///
        m_pSceneManager->renderGraphics               ///
        (this->m_pRenderer);                          ///
	    SDL_RenderPresent(this->m_pRenderer);         ///
        /////////////////////////////////////////////////




    }
    /////////////////////////////////////////////////////////////////////////




    //////////////////////////
    /// Cleaning SDL stuff ///
    //////////////////////////
    
    ///////////////////////////////////////////
    m_pSceneManager->exit(this->m_pWindow) ;///
    m_pSceneManager->releaseInstance()     ;///
    SDL_FreeSurface    (Global::windowIcon);///
    SDL_DestroyRenderer(this->m_pRenderer );///
    SDL_DestroyWindow  (this->m_pWindow   );///
    SDL_Quit           (                  );///
    ///////////////////////////////////////////




}
////////////////////////////////////////////////////////
