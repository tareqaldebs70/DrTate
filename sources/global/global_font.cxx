//////////////////////////////
/// global/global_font.cxx ///
//////////////////////////////




////////////////
/// Includes ///
////////////////

//////////////////////////////
#include"global/global.hxx"///
//////////////////////////////




//////////////////////////
/// Initializing stuff ///
//////////////////////////

////////////////////////////////////////////////////////////////////////
TTF_Font* Global::font = nullptr;                                    ///
SDL_Texture* Global::writeText(                                      ///
    SDL_Renderer* pRenderer,                                         ///
    TTF_Font*     font,                                              ///
    std::string   text,                                              ///
    SDL_Color     color)                                             ///
{                                                                    ///
    SDL_Surface* tempSurface                                         ///
        = TTF_RenderText_Solid(                                      ///
            font,                                                    ///
            text.c_str(),                                            ///
            color);                                                  ///
    SDL_Texture* tempTexture                                         ///
        = SDL_CreateTextureFromSurface(                              ///
            pRenderer,                                               ///
            tempSurface                                              ///
        );                                                           ///
    SDL_FreeSurface(tempSurface);                                    ///
    return tempTexture;                                              ///
}                                                                    ///
SDL_Texture* Global::writeProjectInfo(                               ///
    SDL_Renderer* pRenderer                                          ///
)                                                                    ///
{                                                                    ///
    TTF_Font* tempFont = TTF_OpenFont("assets/Fonts/pixeled.ttf",24);///
    SDL_Texture* tempTexture = Global::writeText(                    ///
        pRenderer,                                                   ///
        tempFont,                                                    ///
        Global::windowTitle,                                         ///
        {255,255,255}                                                ///
    );                                                               ///
    TTF_CloseFont(tempFont);                                         ///
    return tempTexture;                                              ///
}                                                                    ///
////////////////////////////////////////////////////////////////////////