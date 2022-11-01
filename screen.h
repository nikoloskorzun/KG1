#pragma once



#include "lib.h"


using namespace std;
class Screen
{



public:


    
    Screen(uint32_t width, uint32_t height);



    void add_figures();

    int cycle();


    ~Screen();
    







private:



    SDL_Window* win;

    SDL_Renderer* ren = NULL;

    uint32_t width = NULL;

    uint32_t height = NULL;



    Figure* figures = NULL;










};

