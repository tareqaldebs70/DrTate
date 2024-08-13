////////////////////////////////////////
/// setttings_menu/outputs/audio.cxx ///
////////////////////////////////////////




////////////////
/// Includes ///
////////////////

///////////////////////////////////////////////////
#include"scenes/settings_menu/settings_menu.hxx"///
///////////////////////////////////////////////////




using namespace Game;
using namespace Scenes;




/////////////////////
/// playing audio ///
/////////////////////

/////////////////////////////////////////////////////////////////////////
void SettingsMenu::playAudio(void)									  ///
{																 	  ///
	if(!Mix_PlayingMusic())											  ///
	{																  ///
		Mix_PlayMusic(												  ///
		   ResourceManager::g_MusicList["main_menu"],				  ///
		   0													      ///
		);															  ///
	}																  ///
	if(this->m_selected_changed)									  ///
	{																  ///
		this->m_selected_changed = false;							  ///
		Mix_PlayChannel(-1,ResourceManager::g_SoundList["select"],0); ///
	}																  ///
}																	  ///
/////////////////////////////////////////////////////////////////////////