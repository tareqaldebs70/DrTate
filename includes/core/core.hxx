///===--- core/core.hxx - Heart of the program hearder -------*- C++ -*-------===///
///                                                                              ///
/// Part of the @PROJECT_NAME@ Project.                                              ///
/// This class is the heart of the program                                       ///
///                                                                              ///
//===-------------------------------------------------------------------------===///
///                                                                              ///
/// \file                                                                        ///
/// This file declare the the main class                                         ///
///                                                                              ///
///===------------------------------------------------------------------------===///




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




#ifndef __CORE_HXX__
#define __CORE_HXX__




////////////////
/// Includes ///
////////////////

////////////////////////////////////////////
#include<iostream>                       ///
#include<string>                         ///
#include<SDL2/SDL.h>                     ///
#include<SDL2/SDL_image.h>               ///
#include<SDL2/SDL_mixer.h>               ///
#include<SDL2/SDL_ttf.h>                 ///
#include"global/global.hxx"              ///
#include"scene_manager/scene_manager.hxx"///
////////////////////////////////////////////




namespace Application
{




    class Core
    {




        /////////////////////////////////////////////
        /// Stuff that makes this class singleton ///
        /////////////////////////////////////////////

        /////////////////////////////////////////////
    private:                                      ///
        Core(){}                                  ///
        ~Core(){}                                 ///
        static Core* pInstance;                   ///
    public:                                       ///
        static Core* getInstance       (void);    ///
        static void  releaseInstance   (void);    ///
        Core(const Core&)            = delete;    ///
        Core& operator=(const Core&) = delete;    ///
        Core(Core&&)                 = delete;    ///
        Core& operator=(Core&&)      = delete;    ///
        /////////////////////////////////////////////



	
    private:
	SDL_Window*   m_pWindow;
	SDL_Renderer* m_pRenderer;
    public:
        void run(void);
    



    };




}




#endif