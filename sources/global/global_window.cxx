////////////////////////
/// global_window.cxx///
////////////////////////




////////////////
/// Includes ///
////////////////

//////////////////////////////
#include"global/global.hxx"///
#include"common/config.hxx"///
//////////////////////////////




////////////////////////////////////////////
/// Initializing window global Variables ///
////////////////////////////////////////////

/////////////////////////////////////////////////////////////
bool            Global::isWindowRunning     = true   ;    ///
int             Global::windowWidth         = 640    ;    ///
int             Global::windowHeight        = 480    ;    ///
SDL_Surface*    Global::windowIcon          = nullptr;    ///
std::string     Global::windowTitle         =             ///
/**/std::string(PROJECT_NAME)                             ///
+   std::string("  V")                                    ///
+   std::to_string(PROJECT_VERSION_MAJOR)+std::string(".")///
+   std::to_string(PROJECT_VERSION_MINOR)+std::string(".")///
+   std::to_string(PROJECT_VERSION_PATCH)+std::string(".")///
+   std::to_string(PROJECT_VERSION_TWEAK)+std::string(" ")///
+   std::string(PROJECT_STATE)           +std::string(" ")///
+   std::string("Copyright (C) 2024 TarekAldebs  ")      ;///
/////////////////////////////////////////////////////////////