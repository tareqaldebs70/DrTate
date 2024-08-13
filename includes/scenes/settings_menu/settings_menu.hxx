///===---- settings_menu/settings_menu.hxx ------------------*- C++ -*-------===///
///                                                                             ///
/// Part of the @PROJECT_NAME@ Project.                                             ///
///                                                                             ///
//===------------------------------------------------------------------------===///
///                                                                             ///
/// \file                                                                       ///
/// This file contains the settings menu scene methodes                         ///  
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




#ifndef __SETTINGS_MENU_HXX__
#define __SETTINGS_MENU_HXX__




////////////////
/// Includes ///
////////////////

//////////////////////////////////////////////////
#include"scenes/scene.hxx" 		               ///
#include"global/global.hxx"		               ///
#include"resource_manager/resource_manager.hxx"///
#include<SDL2/SDL_mixer.h>		               ///
#include<SDL2/SDL_image.h>		               ///
#include<SDL2/SDL.h>                           ///
//////////////////////////////////////////////////




namespace Game
{




    namespace Scenes
    {




        class SettingsMenu : public Scene
        {

            


        private:




            ///////////////////////////////////////////
            /// Some variables needed by this scene ///
            ///////////////////////////////////////////

            /////////////////////////////////////////////////////////////////////
            SDL_Rect       m_selected_dest_rect; //                           ///
            uint8_t        m_choice = 0; // determine which option is selected///
            //                           // in the main menu                  ///
            const uint8_t* m_key_state;                                       ///
            bool           m_selected_changed = false;                        ///
            ///                                                               ///
            SDL_Rect       m_volume_bar_dest_rect; // common rect             ///
            SDL_Rect       m_volume_bar_src_rect;                             ///
            /////////////////////////////////////////////////////////////////////
            



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