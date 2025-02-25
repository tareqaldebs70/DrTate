/////////////////////////////////////////////
/// resource_manager/resource_manager.cxx ///
/////////////////////////////////////////////




////////////////
/// Includes ///
////////////////

//////////////////////////////////////////////////
#include"resource_manager/resource_manager.hxx"///
//////////////////////////////////////////////////




using namespace Game;



///////////////////////////////////////////////////
/// Texture list that will be used by the scene ///
///////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
std::map<std::string,SDL_Texture*> ResourceManager::g_TexturesList;///
//////////////////////////////////////////////////////////////////////



////////////////////////////////////////////
/// SFX list that will be used the scene ///
////////////////////////////////////////////

///////////////////////////////////////////////////////////////////
std::map<std::string,Mix_Chunk*>   ResourceManager::g_SoundList;///
///////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////
/// Music list that will be used by the scenes ///
//////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
std::map<std::string,Mix_Music*>   ResourceManager::g_MusicList; ///
////////////////////////////////////////////////////////////////////