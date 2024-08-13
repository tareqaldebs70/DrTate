///===--- scene_manager/scene_manager - scene manager class -*- C++ -*-------===///
///                                                                             ///
/// Part of the @PROJECT_NAME@ Project.                                             ///
///                                                                             ///
///===-----------------------------------------------------------------------===///
///                                                                             ///
/// \file                                                                       ///
/// The scene manager class is declared here                                    ///  
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




#ifndef __SCENE_MANAGER_HXX__
#define __SCENE_MANAGER_HXX__




////////////////
/// Includes ///
////////////////

//////////////////////////////////////////
#include<string>                       ///
#include<SDL2/SDL.h>                   ///
#include"scenes/scene.hxx"             ///
#include"global/global.hxx"            ///
#include"scene_manager/scenes_list.hxx"///
//////////////////////////////////////////




namespace Game
{




    class SceneManager
    {




        /////////////////////////////////////////////
        /// Stuff that makes this class Singleton ///
        /////////////////////////////////////////////

        //////////////////////////////////////////////////////////
    private:                                                   ///
        SceneManager(){}                                       ///
        ~SceneManager(){}                                      ///
        static SceneManager* pInstance                        ;///
    public:                                                    ///
        static SceneManager* getInstance(void)                ;///
        static void          releaseInstance(void)            ;///
        SceneManager           (const SceneManager&)  = delete;///
        SceneManager& operator=(const SceneManager&)  = delete;///
        SceneManager           (      SceneManager&&) = delete;///
        SceneManager& operator=(      SceneManager&&) = delete;///
        //////////////////////////////////////////////////////////




    private:
        uint8_t     m_CurrentScene      = NULL_SCENE;
        Scene*      m_pCurrentScene     = nullptr;
    public:




        ///////////////////////////
        /// scene Loading stuff ///
        ///////////////////////////

        ////////////////////////////////////////////////////////// 
        void init(SDL_Window* pWindow,SDL_Renderer* pRenderer);///
        void exit(SDL_Window* pWindow                        );///
        //////////////////////////////////////////////////////////




        //////////////////////
        /// Input methodes ///
        //////////////////////

        //////////////////////////////////////////////////////////////////////////
        ///     KeyBoard stuff                                                 ///
        void whenKeyboardKeyIsPressed (SDL_Window* pWindow, SDL_Event* pEvent);///
        void whenKeyboardKeyIsReleased(SDL_Window* pWindow, SDL_Event* pEvent);///
        ///     Mouse stuff                                                    ///
        void whenMouseButtonIsPressed (SDL_Window* pWindow, SDL_Event* pEvent);///
        void whenMouseButtonIsReleased(SDL_Window* pWindow, SDL_Event* pEvent);///
        void whenMouseMoves           (SDL_Window* pWindow, SDL_Event* pEvent);///
        void whenMouseWheelIsRolled   (SDL_Window* pWindow, SDL_Event* pEvent);///
        //////////////////////////////////////////////////////////////////////////




        //////////////////////////////////////////////////////////////////
        // update Simulation like AI, Physics , Logic and moving player///
        //////////////////////////////////////////////////////////////////

        /////////////////////////////////////////////
        void updateSimulation(uint64_t deltaTime);///
        /////////////////////////////////////////////




        //////////////
        /// Output ///
        //////////////

        ////////////////////////////////////////////////
        void playAudio     (        void           );///
        void renderGraphics(SDL_Renderer* pRenderer);///
        ////////////////////////////////////////////////




    };




}




#endif