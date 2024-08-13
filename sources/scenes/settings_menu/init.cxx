//////////////////////////////
/// settings_menu/init.cxx ///
//////////////////////////////




////////////////
/// Includes ///
////////////////

////////////////////////////////////////////////////
#include"scenes/settings_menu/settings_menu.hxx" ///
////////////////////////////////////////////////////




using namespace Game;
using namespace Scenes;




//////////////////////////
/// initializing scene ///
//////////////////////////

////////////////////////////////////////////////////////////////////////////////
void SettingsMenu::init(SDL_Window* pWindow,SDL_Renderer* pRenderer)		 ///
{																			 ///
	Global::loadSettings();													 ///
	SDL_RenderSetLogicalSize(												 ///
        	pRenderer,														 ///
        	Global::windowWidth,											 ///
        	Global::windowHeight											 ///
   	);																		 ///
	if(!Global::windowed)													 ///
		SDL_SetWindowFullscreen(pWindow,SDL_WINDOW_FULLSCREEN);				 ///
	else																	 ///
		SDL_SetWindowFullscreen(pWindow,0);									 ///
	Mix_MasterVolume(static_cast<int>(Global::master_volume));			     ///
	Mix_Volume(-1,static_cast<int>(Global::sfx_volume));					 ///
	Mix_VolumeMusic(static_cast<int>(Global::music_volume));				 ///
	if(!ResourceManager::g_TexturesList.empty())							 ///
		ResourceManager::g_TexturesList.clear();							 ///
	if(!ResourceManager::g_SoundList.empty())								 ///
		ResourceManager::g_SoundList.clear();								 ///
	// loading some freaky sounds											 ///
	ResourceManager::g_SoundList["select"]									 ///
		= Mix_LoadWAV("assets/SFX/select.wav");								 ///
	//// load some freaky textures											 ///
	ResourceManager::g_TexturesList["settings_menu_background"]				 ///
		= IMG_LoadTexture(pRenderer,"assets/GFX/settings/background.png");	 ///
	ResourceManager::g_TexturesList["volume"]								 ///
		= IMG_LoadTexture(pRenderer,"assets/GFX/settings/volume_bar.png");   ///
	ResourceManager::g_TexturesList["select"]								 ///
		= IMG_LoadTexture(pRenderer,"assets/GFX/settings/select.png");		 ///
	this->m_selected_dest_rect.x      = 64 							  ;		 ///
	this->m_selected_dest_rect.y      = 192							  ;      ///
	this->m_selected_dest_rect.w 	  = 512							  ;      ///
	this->m_selected_dest_rect.h      = 32 							  ;      ///
	this->m_volume_bar_dest_rect.x = (9*32						     );      ///
	this->m_volume_bar_dest_rect.y = (6*32						     );      ///
	this->m_volume_bar_dest_rect.w = (32*8						     );      ///
	this->m_volume_bar_dest_rect.h = (32*1                           );      ///
	this->m_volume_bar_src_rect.x  =     0 							  ;		 ///
	this->m_volume_bar_src_rect.y  = ((Global::master_volume/16) * 32);		 ///
	this->m_volume_bar_src_rect.w  = (8*32							 );      ///
	this->m_volume_bar_src_rect.h  = (1*32							 );		 ///
}																			 ///
////////////////////////////////////////////////////////////////////////////////