/////////////////////
/// main/main.cxx ///
/////////////////////




#include"main.hxx"




START_PROGRAM




    ////////////////////
    /// Stating core ///
    ////////////////////

    /////////////////////////////////////////////////////////////////
    Application::Core* m_pCore = Application::Core::getInstance();///
    /////////////////////////////////////////////////////////////////




    ///////////////////////////////////////////////
    /// Handleing program arguments in terminal ///
    ///////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////////////
    if(PROGRAM_ARGUMENTS_DETECTED)                                                             ///
    {                                                                                          ///
        std::string m_arg1 = argv[1];                                                          ///
        if((m_arg1 == "--help") || (m_arg1 == "-h"))                                           ///
        {                                                                                      ///
            std::cout << PROJECT_NAME << "  " << "Copyright (C) 2024  TareqAldebs\n";          ///
            std::cout << "This program comes with ABSOLUTELY NO WARRANTY;\n";                  ///
            std::cout << "This is free software, and you are welcome to redistribute it\n";    ///
            std::cout << "under certain conditions;\n\n";                                      ///
            std::cout << "Usage: " << PROJECT_NAME << " [Options]...\n";                       ///
            std::cout << "Options:\n";                                                         ///
            std::cout << "  --version or -v     Display this Program version\n";               ///
            std::cout << "  --help or -h        Display this information\n";                   ///
        }                                                                                      ///
        if((m_arg1 == "--version") || (m_arg1 == "-v"))                                        ///
        {                                                                                      ///
            std::cout << PROJECT_NAME                                                          ///
            << "  V"                                                                           ///
            << PROJECT_VERSION_MAJOR << "."                                                    ///
            << PROJECT_VERSION_MINOR << "."                                                    ///
            << PROJECT_VERSION_PATCH << "."                                                    ///
            << PROJECT_VERSION_TWEAK << "\n";                                                  ///
            std::cout << PROJECT_NAME << "  " << "Copyright (C) 2024  TareqAldebs\n";          ///
            std::cout << "This program comes with ABSOLUTELY NO WARRANTY;\n";                  ///
            std::cout << "This is free software, and you are welcome to redistribute it\n";    ///
            std::cout << "under certain conditions;\n\n";                                      ///
        }                                                                                      ///
    }                                                                                          ///
    //////////////////////////////////////////////////////////////////////////////////////////////




    ////////////////////////////////////////////////////
    /// running program if no arguments was provided ///
    ////////////////////////////////////////////////////

    /////////////////////////////////
    else // just run the program  ///
    {                             ///
        m_pCore->run();           ///
    }                             ///
    /////////////////////////////////




    ///////////////////////
    /// Destroying Core ///
    ///////////////////////

    //////////////////////////////
    m_pCore->releaseInstance();///
    EXIT_PROGRAM_SUCCEED       ///
    //////////////////////////////




END___PROGRAM