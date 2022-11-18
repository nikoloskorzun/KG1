#pragma once

#include <iostream>
#include <SDL.h>

#include "figure.h"
#include "light_system.h"


#include "polygone.h"
#include "shadow_polygone.h"

#include "template_functions.h"





/*

*/





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

    Light_system* light_system; // она одна


    Base_polygone** polygones;


    //Polygone* polygones;


    //Shadow_polygone* shadow_polygones;

    size_t polygone_count;

    
    void draw_poligones(SDL_Renderer* ren);
    void painter_algorithm();

    




};

