#include"core/core.hxx"



using namespace Application;




Core* Core::pInstance = nullptr;




Core* Core::getInstance(void)
{
    if(pInstance == nullptr)
    {
        pInstance = new Core;
    }
    return pInstance;
}




void Core::releaseInstance(void)
{
    delete pInstance;
}