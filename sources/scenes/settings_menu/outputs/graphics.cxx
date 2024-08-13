///////////////////////////////////////////
/// settingsa_menu/outputs/graphics.hxx ///
///////////////////////////////////////////




////////////////
/// Includes ///
////////////////

////////////////////////////////////////////////////
#include"scenes/settings_menu/settings_menu.hxx" ///
////////////////////////////////////////////////////




using namespace Game;
using namespace Scenes;




////////////////////////////////
/// rendering scene graphics ///
////////////////////////////////

/////////////////////////////////////////////////////////////////////////
void SettingsMenu::renderGraphics(SDL_Renderer* pRenderer)			  ///
{																	  ///
	SDL_RenderCopy(													  ///
		pRenderer,													  ///
		ResourceManager::g_TexturesList["settings_menu_background"]	  ///
		,NULL														  ///
		,															  ///
		NULL);														  ///
	switch(this->m_choice)											  ///
	{																  ///
		case 0: // master volume									  ///
			this->m_selected_dest_rect.y = 192;						  ///
			break;													  ///
		case 1: // SFXs volume 										  ///
			this->m_selected_dest_rect.y = 192 + 32;				  ///
			break;													  ///
		case 2: // Music volume										  ///
			this->m_selected_dest_rect.y = 192 + (32*2);			  ///
			break;													  ///
		case 3: // go back option									  ///
			this->m_selected_dest_rect.y = 192 + (32*3);			  ///
			break;													  ///
	}																  ///
	SDL_RenderCopy(													  ///
		pRenderer,													  ///
		ResourceManager::g_TexturesList["select"],				      ///
		NULL,														  ///
		&this->m_selected_dest_rect);								  ///
	// drawing volume_bars											  ///
	// master volume bar											  ///
	this->m_volume_bar_dest_rect.y = (6*32);						  ///
	// rendering volume bar depending on master volume value	      ///
	this->m_volume_bar_src_rect.y = (Global::master_volume/16) * 32;  ///
	SDL_RenderCopy(													  ///
		pRenderer,													  ///
		ResourceManager::g_TexturesList["volume"],					  ///
		&this->m_volume_bar_src_rect,								  ///
		&this->m_volume_bar_dest_rect								  ///
	);																  ///
	// rendering volume bar of sfx volume 							  ///
	this->m_volume_bar_dest_rect.y = (7*32);						  ///
	this->m_volume_bar_src_rect.y = (Global::sfx_volume/16)*32;		  ///
	SDL_RenderCopy(													  ///
		pRenderer,													  ///
		ResourceManager::g_TexturesList["volume"],					  ///
		&this->m_volume_bar_src_rect,								  ///
		&this->m_volume_bar_dest_rect								  ///
	);																  ///
	// rendering volume bar of music 								  ///
	this->m_volume_bar_dest_rect.y = (8*32);						  ///
	this->m_volume_bar_src_rect.y = (Global::music_volume/16)*32;	  ///
	SDL_RenderCopy(													  ///
		pRenderer,													  ///
		ResourceManager::g_TexturesList["volume"],					  ///
		&this->m_volume_bar_src_rect,								  ///
		&this->m_volume_bar_dest_rect								  ///
	);																  ///
}																	  ///
/////////////////////////////////////////////////////////////////////////