///===---- scenes/scene.hxx - scene abstract class    -------*- C++ -*-------===///
///                                                                             ///
/// Part of the @PROJECT_NAME@ Project.                                             ///
///                                                                             ///
//===------------------------------------------------------------------------===///
///                                                                             ///
/// \file                                                                       ///
/// This file contains the scene abstract class                                 ///  
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




#ifndef __SCENE_HXX__
#define __SCENE_HXX__




////////////////
/// Includes ///
////////////////

///////////////////////
#include<SDL2/SDL.h>///
///////////////////////




namespace Game
{




    class Scene
    {




    public:




        ///////////////////////////
        /// scene Loading stuff ///
        ///////////////////////////

        ////////////////////////////////////////////////////////////////////// 
        virtual void init(SDL_Window* pWindow,SDL_Renderer* pRenderer) = 0;///
        virtual void exit(SDL_Window* pWindow                        ) = 0;///
        //////////////////////////////////////////////////////////////////////




        //////////////////////
        /// Input methodes ///
        //////////////////////

        //////////////////////////////////////////////////////////////////////////////////////
        ///     KeyBoard stuff                                                             ///
        virtual void whenKeyboardKeyIsPressed (SDL_Window* pWindow, SDL_Event* pEvent) = 0;///
        virtual void whenKeyboardKeyIsReleased(SDL_Window* pWindow, SDL_Event* pEvent) = 0;///
        ///     Mouse stuff                                                                ///
        virtual void whenMouseButtonIsPressed (SDL_Window* pWindow, SDL_Event* pEvent) = 0;///
        virtual void whenMouseButtonIsReleased(SDL_Window* pWindow, SDL_Event* pEvent) = 0;///
        virtual void whenMouseMoves           (SDL_Window* pWindow, SDL_Event* pEvent) = 0;///
        virtual void whenMouseWheelIsRolled   (SDL_Window* pWindow, SDL_Event* pEvent) = 0;///
        //////////////////////////////////////////////////////////////////////////////////////




        //////////////////////////////////////////////////////////////////
        // update Simulation like AI, Physics , Logic and moving player///
        //////////////////////////////////////////////////////////////////

        /////////////////////////////////////////////////////////
        virtual void updateSimulation(uint64_t deltaTime) = 0;///
        /////////////////////////////////////////////////////////




        //////////////
        /// Output ///
        //////////////

        ////////////////////////////////////////////////////////////
        virtual void playAudio     (        void           ) = 0;///
        virtual void renderGraphics(SDL_Renderer* pRenderer) = 0;///
        ////////////////////////////////////////////////////////////




        virtual ~Scene() = default;



        
    };




}




#endif