///===--- resource_manager/resource_manager.hxx -------------*- C++ -*-------===///
///                                                                             ///
/// Part of the @PROJECT_NAME@ Project.                                             ///
///                                                                             ///
///===-----------------------------------------------------------------------===///
///                                                                             ///
/// \file                                                                       ///
/// This is resource manager that prepare and orginize resources for scenes     ///
/// Like textures and sfx and other                                             /// 
///                                                                             ///
///===-----------------------------------------------------------------------===///




///==---------------------------------------------------------------------===///
///@PROJECT_NAME@ It's a platformer game                                         ///
///Copyright (C) 2024  TareqAldebs                                           ///
///==---------------------------------------------------------------------===///
///This program is free software: you can redistribute it and/or modify      ///
///it under the terms of the GNU General Public License as published by      ///
///the Free Software Foundation, either version 3 of the License, or         ///
///(at your option) any later version.                                       ///
///==---------------------------------------------------------------------===///
///This program is distributed in the hope that it will be useful,           ///
///but WITHOUT ANY WARRANTY; without even the implied warranty of            ///
///MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             ///
///GNU General Public License for more details.                              ///
///==---------------------------------------------------------------------===///
///You should have received a copy of the GNU General Public License         ///
///along with this program.  If not, see:                                    ///
/// https://www.gnu.org/licenses/gpl-3.0.en.html.                            ///
///==---------------------------------------------------------------------===///




#ifndef __RESOURCE_MANAGER_HXX__
#define __RESOURCE_MANAGER_HXX__




////////////////
/// Includes ///
////////////////

/////////////////////////////
#include<SDL2/SDL.h>      ///
#include<SDL2/SDL_image.h>///
#include<SDL2/SDL_mixer.h>///
#include<string>          ///
#include<iostream>        ///
#include<map>             ///
/////////////////////////////




namespace Game
{




    struct ResourceManager
    {




        /////////////////////
        /// Textures List ///
        /////////////////////

        ////////////////////////////////////////////////////////////
        static std::map<std::string,SDL_Texture*> g_TexturesList;///
        ////////////////////////////////////////////////////////////




        ////////////////
        /// SFX List ///
        ///////////////

        ////////////////////////////////////////////////////////
        static std::map<std::string,Mix_Chunk*> g_SoundList; ///
        ////////////////////////////////////////////////////////




        //////////////////
        /// Music List ///
        //////////////////

        ///////////////////////////////////////////////////////
        static std::map<std::string,Mix_Music*> g_MusicList;///
        ///////////////////////////////////////////////////////



        
    };




}




#endif