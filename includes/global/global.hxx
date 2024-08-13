///===--- global/global.hxx - global variables Header  -------*- C++ -*-------===///
///                                                                              ///
/// Part of the @PROJECT_NAME@ Project.                                              ///
/// This file contains all global variables that will be used                    ///
///                                                                              ///
//===-------------------------------------------------------------------------===///
///                                                                              ///
/// \file                                                                        ///
/// This file declare the the global variables                                   ///
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




#ifndef __GLOBAL_HXX__
#define __GLOBAL_HXX__




////////////////
/// Includes ///
////////////////

//////////////////////////////////////////
#include<string>                       ///
#include<SDL2/SDL.h>                   ///
#include<SDL2/SDL_ttf.h>               ///
#include"common/config.hxx"            ///
#include"scene_manager/scenes_list.hxx"///
//////////////////////////////////////////




struct Global
{




    ////////////////////
    /// Window stuff ///
    ////////////////////

    //////////////////////////////////////////
    static bool            isWindowRunning;///
    static std::string     windowTitle    ;///
    static int             windowWidth    ;///
    static int             windowHeight   ;///
    static SDL_Surface*    windowIcon     ;///
    //////////////////////////////////////////




    //////////////////////////
    /// SceneManager stuff ///
    //////////////////////////

    ////////////////////////////////
    static uint8_t selectedScene;///
    ////////////////////////////////




    //////////////////////
    /// Settings stuff ///
    //////////////////////

    //////////////////////////////////////
    static void loadSettings(void);    ///
    static void saveSettings(void);    ///
    static bool windowed;              ///
    static uint8_t master_volume;      ///
    static uint8_t sfx_volume;         ///
    static uint8_t music_volume;       ///
    //////////////////////////////////////




    ///////////////////
    /// Fonts stuff ///
    ///////////////////

    //////////////////////////////////////////
    static TTF_Font*       font     ;      ///
    static SDL_Texture*    writeProjectInfo///
    (SDL_Renderer*pRenderer);              ///
    static SDL_Texture*    writeText(      ///
        SDL_Renderer*pRenderer,            ///
        TTF_Font*Font,                     ///
        std::string text,                  ///
        SDL_Color color);                  ///
    //////////////////////////////////////////




};




#endif