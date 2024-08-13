//////////////////////////////////
/// global/global_settings.cxx ///
//////////////////////////////////




///////////////
/// include ///
///////////////

//////////////////////////////
#include<SDL2/SDL_mixer.h> ///
#include"global/global.hxx"///
#include<fstream>          ///
#include<string>           ///
#include<iostream>         ///
//////////////////////////////




//////////////////////////////////////////
/// Initializing Settings global stuff ///
//////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////
///                                                                                     ///
///                                                                                     ///
///                                                                                     ///
///                                                                                     ///
//////////////////////////////////////////////                                          ///
/// Initializing settings global variables ///                                          ///
//////////////////////////////////////////////                                          ///
///                                                                                     ///
///////////////////////////////////////////////////////////////////////                 ///
bool    Global::windowed = true; // window is fullscreen by default ///                 ///
uint8_t Global::master_volume = MIX_MAX_VOLUME;///                  ///                 ///
uint8_t Global::sfx_volume    = MIX_MAX_VOLUME;                     ///                 ///
uint8_t Global::music_volume  = MIX_MAX_VOLUME;                     ///                 ///
///////////////////////////////////////////////////////////////////////                 ///
///                                                                                     ///
///                                                                                     ///
///                                                                                     ///
///                                                                                     ///
//////////////////////////////////////////                                              ///
/// Loading settings form settings.ini ///                                              ///
//////////////////////////////////////////                                              ///
///                                                                                     ///
/////////////////////////////////////////////////////////////////////////               ///
/// @brief simply loads settings from a file named settings.ini       ///               ///
void Global::loadSettings(void)                                       ///               ///
{                                                                     ///               ///
    std::fstream file;                                                ///               ///
    file.open("settings.ini");                                        ///               ///
    uint8_t index =0;                                                 ///               ///
    std::string line;                                                 ///               ///
    while(std::getline(file,line))                                    ///               ///
    {                                                                 ///               ///
        switch(index)                                                 ///               ///
        {                                                             ///               ///
            case 1:                                                   ///               ///
                line.erase(0,11);                                     ///               ///
                if(line=="true")                                      ///               ///
                    windowed = true;                                  ///               ///
                else                                                  ///               ///
                    windowed = false;                                 ///               ///
                break;                                                ///               ///
            case 2:                                                   ///               ///
                line.erase(0,16);                                     ///               ///
                master_volume = static_cast<uint8_t>(std::stoi(line));///               ///
                break;                                                ///               ///
            case 3:                                                   ///               ///
                line.erase(0,13);                                     ///               ///
                sfx_volume = static_cast<uint8_t>(std::stoi(line));   ///               ///
                break;                                                ///               ///
            case 4:                                                   ///               ///
                line.erase(0,15);                                     ///               ///
                music_volume = static_cast<uint8_t>(std::stoi(line)); ///               ///
                break;                                                ///               ///
            default:                                                  ///               ///
                break;                                                ///               ///
        }                                                             ///               ///
        index++;                                                      ///               ///
    }                                                                 ///               ///
    ///                                                               ///               ///
    ///                                                               ///               ///
    file.close();                                                     ///               ///
}                                                                     ///               ///
/////////////////////////////////////////////////////////////////////////               ///
///                                                                                     ///
///                                                                                     ///
///                                                                                     ///
///                                                                                     ///
////////////////////////////////////////////                                            ///
/// Saving settings to settings.ini file ///                                            ///
////////////////////////////////////////////                                            ///
///                                                                                     ///
///////////////////////////////////////////////////////////                             ///
void Global::saveSettings(void)                         ///                             ///
{                                                       ///                             ///
    std::fstream file;                                  ///                             ///
    file.open("settings.ini");                          ///                             ///
    file << "[settings]\n";                             ///                             ///
    if(windowed)                                        ///                             ///
        file << "windowed = true\n";                    ///                             ///
    else                                                ///                             ///
        file << "windowed = false\n";                   ///                             ///
    file << std::string("master_volume = ")             ///                             ///
    + std::to_string(master_volume) + std::string("\n");///                             ///
    file << std::string("sfx_volume = ")                                                ///
    + std::to_string(sfx_volume) + std::string("\n");                                   ///
    file << std::string("music_volume = ")                                              ///
    + std::to_string(music_volume) + std::string("\n");                                 ///
    file << std::string("\r");                                                          ///
    file.close();                                                                       ///
}                                                                                       ///
///////////////////////////////////////////////////////////////////////////////////////////