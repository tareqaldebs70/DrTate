///===--- scenes/main_menu.hxx - main menu scene        -----*- C++ -*-------===///
///                                                                             ///
/// Part of the DoctorTate Project.                                             ///
///                                                                             ///
///===-----------------------------------------------------------------------===///
///                                                                             ///
/// \file                                                                       ///
/// The first scene to show when program starts                                 ///  
///                                                                             ///
///===-----------------------------------------------------------------------===///




///==---------------------------------------------------------------------===///
///DoctorTate It's a platformer game                                         ///
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




#ifndef __MAIN_MENU_HXX__
#define __MAIN_MENU_HXX__




////////////////
/// Includes ///
////////////////

/////////////////////////////
#include"scenes/scene.hxx"///
/////////////////////////////




namespace Game
{




    namespace Scenes
    {
        



        class MainMenu : public Scene
        {




        public:




            ///////////////////////////
            /// scene Loading stuff ///
            ///////////////////////////

            //////////////////////////////////////////////////////////////// 
            void init(SDL_Window* pWindow,SDL_Renderer* pRenderer) final;///
            void exit(SDL_Window* pWindow                        ) final;///
            ////////////////////////////////////////////////////////////////

            //////////////////////
            /// Input methodes ///
            //////////////////////

            ////////////////////////////////////////////////////////////////////////////////
            ///     KeyBoard stuff                                                       ///
            void whenKeyboardKeyIsPressed (SDL_Window* pWindow, SDL_Event* pEvent) final;///
            void whenKeyboardKeyIsReleased(SDL_Window* pWindow, SDL_Event* pEvent) final;///
            ///     Mouse stuff                                                          ///
            void whenMouseButtonIsPressed (SDL_Window* pWindow, SDL_Event* pEvent) final;///
            void whenMouseButtonIsReleased(SDL_Window* pWindow, SDL_Event* pEvent) final;///
            void whenMouseMoves           (SDL_Window* pWindow, SDL_Event* pEvent) final;///
            void whenMouseWheelIsRolled   (SDL_Window* pWindow, SDL_Event* pEvent) final;///
            ////////////////////////////////////////////////////////////////////////////////




            //////////////////////////////////////////////////////////////////
            // update Simulation like AI, Physics , Logic and moving player///
            //////////////////////////////////////////////////////////////////

            ///////////////////////////////////////////////////
            void updateSimulation(uint64_t deltaTime) final;///
            ///////////////////////////////////////////////////



            //////////////
            /// Output ///
            //////////////

            //////////////////////////////////////////////////////
            void playAudio     (        void           ) final;///
            void renderGraphics(SDL_Renderer* pRenderer) final;///
            //////////////////////////////////////////////////////




        };




    }




}




#endif
