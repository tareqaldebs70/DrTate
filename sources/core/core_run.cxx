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
    /// Running the application///
    //////////////////////////////

    //////////////////////////////////////////////////
    while(Global::isWindowRunning)
    {




        ////////////////////////////////
        /// Load Scene if not loaded ///
        ////////////////////////////////

        ///////////////////////////////////////////////////

        ///////////////////////////////////////////////////




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
                    break;                                    ///        ///
                case SDL_KEYUP:                               ///        ///
                    break;                                    ///        ///
                case SDL_MOUSEBUTTONDOWN:                     ///        ///
                    break;                                    ///        ///
                case SDL_MOUSEBUTTONUP:                       ///        ///
                    break;                                    ///        ///
                case SDL_MOUSEMOTION:                         ///        ///
                    break;                                    ///        ///
                case SDL_MOUSEWHEEL:                          ///        ///
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

        ////////////////////////////////////////

        ////////////////////////////////////////




        /////////////////////
        /// Playing audio ///
        /////////////////////

        ///////////////////////////////////////////

        ///////////////////////////////////////////




        /////////////////
        /// Rendering ///
        /////////////////

        /////////////////////////////////////////////////
	    SDL_SetRenderDrawColor(                       ///
			    this->m_pRenderer,                    ///
			    0,0,0,255                             ///
			    );                                    ///
	    SDL_RenderClear  (this->m_pRenderer);         ///
        ///                                           ///
	    SDL_RenderPresent(this->m_pRenderer);         ///
        /////////////////////////////////////////////////




    }
    /////////////////////////////////////////////////////////////////////////




    //////////////////////////
    /// Cleaning SDL stuff ///
    //////////////////////////
    
    ///////////////////////////////////////////
    SDL_FreeSurface    (Global::windowIcon);///
    SDL_DestroyRenderer(this->m_pRenderer );///
    SDL_DestroyWindow  (this->m_pWindow   );///
    SDL_Quit           (                  );///
    ///////////////////////////////////////////




}
////////////////////////////////////////////////////////
