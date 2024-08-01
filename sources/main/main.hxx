///===-- main/main.hxx --------------- macros for main.cxx -------*- C++ -*-===///
///                                                                            ///
/// Part of the DoctorTate Project.                                            ///
///                                                                            ///
///===----------------------------------------------------------------------===///
///                                                                            ///
/// @file                                                                      ///
/// @author TareqAldebs                                                        ///
/// This file contains the macros for main.cxx.                                ///
///                                                                            ///
///===----------------------------------------------------------------------===///




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




#ifndef __MAIN_HXX__




////////////////////
//// Includes   ////
////////////////////

/////////////////////////////
#include<cstdlib>
#include<iostream>
#include"common/config.hxx"
#include<string>
#include"core/core.hxx"
/////////////////////////////




////////////////////
////   Macros   ////
////////////////////

////////////////////////////////////////////////////////////////////
#define START_PROGRAM              int main(int argc,char**argv){/// 
#define END___PROGRAM              /*Main entry point end*/}     ///
#define EXIT_PROGRAM_SUCCEED       exit(0);                      ///
#define EXIT_PROGRAM_ERROR_OCCURD  exit(1);                      ///
#define PROGRAM_ARGUMENTS_DETECTED (argc > 1)                    ///
////////////////////////////////////////////////////////////////////




#define __MAIN_HXX__
#endif
