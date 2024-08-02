////////////////////
/// core_run.cxx ///
////////////////////




////////////////
/// Includes ///
////////////////

//////////////////////////////
#include"core/core.hxx"    ///
#include"common/config.hxx"///
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
		    "test window",
		    SDL_WINDOWPOS_CENTERED,
		    SDL_WINDOWPOS_CENTERED,
		    640,480,
		    SDL_WINDOW_SHOWN 
		    );
    this->m_pRenderer = SDL_CreateRenderer(
		    this->m_pWindow,
		    -1,
		    SDL_RENDERER_ACCELERATED
		    );
    ///////////////////////////////////////




    //////////////////////////////
    /// Running the application///
    //////////////////////////////

    //////////////////////////////////////////////////
    bool running = true;
    while(running)
    {
	    SDL_Event event;
	    while(SDL_PollEvent(&event))
	    {
		    switch(event.type)
		    {
			    case SDL_QUIT:
				    running = false;
				    break;
			    default:
				    break;
		    }
	    }

	    SDL_SetRenderDrawColor(
			    this->m_pRenderer,
			    0,0,255,255
			    );
	    SDL_RenderClear  (this->m_pRenderer);

	    SDL_RenderPresent(this->m_pRenderer);
    }
    //////////////////////////////////////////////////




    //////////////////////////
    /// Cleaning SDL stuff ///
    //////////////////////////
    
    //////////////////////////////////////////
    SDL_DestroyRenderer(this->m_pRenderer);///
    SDL_DestroyWindow  (this->m_pWindow  );///
    SDL_Quit           (                 );///
    //////////////////////////////////////////




}
////////////////////////////////////////////////////////
