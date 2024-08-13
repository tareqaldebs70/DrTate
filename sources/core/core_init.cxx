//////////////////////////
/// core/core_init.cxx ///
//////////////////////////




////////////////
/// Includes ///
////////////////

//////////////////////////
#include"core/core.hxx"///
//////////////////////////




using namespace Application;




////////////////////////////////////////////////////////////
/// Initializing methodes that makes the class singleton ///
////////////////////////////////////////////////////////////

///////////////////////////////////
Core* Core::pInstance = nullptr;///
Core* Core::getInstance(void)   ///
{                               ///
    if(pInstance == nullptr)    ///
    {                           ///
        pInstance = new Core;   ///
    }                           ///
    return pInstance;           ///
}                               ///
void Core::releaseInstance(void)///
{                               ///
    delete pInstance;           ///
}                               ///
///////////////////////////////////