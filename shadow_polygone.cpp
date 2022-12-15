
#pragma once
#include <iostream>

#include <SDL.h>

#include "shadow_polygone.h"


using namespace std;






void Shadow_polygone::set_vertexes(size_t count, double** v)
{

    for (register size_t i = 0; i < count; i++)
        for (register size_t j = 0; j < 3; j++)
            this->coords[i][j] = v[i][j];

    

    this->count_of_vertex = count;





}



Shadow_polygone::Shadow_polygone(const Shadow_polygone& polygone_copy)
{

    this->c = polygone_copy.c;

    //cout << "copy error\n";

    this->z = polygone_copy.z;
    
    this->coords = allocate_memory_for_N_M_array<double>(5, 3);
    for (register size_t i = 0; i < 5; i++)
        for (register size_t j = 0; j < 3; j++)
            this->coords[i][j] = polygone_copy.coords[i][j];



    this->count_of_vertex = polygone_copy.count_of_vertex;



    //cout << "copy ERROR\n";

}



Shadow_polygone::Shadow_polygone()
{

    this->z = NULL;
    this->coords = allocate_memory_for_N_M_array<double>(5, 3);
    

    this->count_of_vertex = 0;


    this->c.r =255;
    this->c.g = 255;
    this->c.b = 255;
    this->c.a = 255;


}


Shadow_polygone& Shadow_polygone::operator=(const Shadow_polygone& right) {



    //проверка на самоприсваивание
    if (this == &right) {
        return *this;
    }


    this->z = right.z;
    this->coords = allocate_memory_for_N_M_array<double>(5, 3);
    for (register size_t i = 0; i < 5; i++)
        for (register size_t j = 0; j < 3; j++)
            this->coords[i][j] = right.coords[i][j];


    this->count_of_vertex = right.count_of_vertex;




    this->c  = right.c;




    return *this;
}

Shadow_polygone::~Shadow_polygone()
{
    if (coords)
        free_memory_for_N_M_array<double>(coords, 5, 3);

    return;

}




void Shadow_polygone::set_z()
{
 

    if (!count_of_vertex)
        return;



    double az = coords[0][2], bz = coords[1][2], cz = coords[2][2];


    z = (az + bz + cz) / 3;


    return;






}

void Shadow_polygone::set_сolor(Color сolor)
{
    this->c.r = 255;
    this->c.g = 255;
    this->c.b = 255;
    this->c.a = 255;
}



Color Shadow_polygone::get_сolor()
{
    return c;
}

void  Shadow_polygone::draw(SDL_Renderer* ren)
{

   // return;

    /*
    double a = f[0][1] * (f[1][2] - f[2][2]) + f[1][1] * (f[2][2] - f[0][2]) + f[2][1] * (f[0][2] - f[1][2]);
    double b = f[0][0] * (f[2][2] - f[1][2]) + f[1][0] * (f[0][2] - f[2][2]) + f[2][0] * (f[1][2] - f[0][2]);
    //double c = f[0][0] * (f[1][1] - f[2][1]) + f[1][0] * (f[2][1] - f[0][1]) + f[2][0] * (f[0][1] - f[1][1]);

    double x1 = (f[0][0] + f[1][0] + f[2][0]) / 3;
    double y1 = (f[0][1] + f[1][1] + f[2][1]) / 3;
    double x2 = x1 + a;
    double y2 = y1 + b;
    Нормаль

   SDL_RenderDrawLine(ren, x1, y1, x2, y2);
   */
    if (this->count_of_vertex != 3)
        return;
    

    SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, c.a);
    SDL_RenderDrawLine(ren, coords[0][0], coords[0][1], coords[1][0], coords[1][1]);
    SDL_RenderDrawLine(ren, coords[0][0], coords[0][1], coords[2][0], coords[2][1]);
    SDL_RenderDrawLine(ren, coords[2][0], coords[2][1], coords[1][0], coords[1][1]);

    //return;



    double* d_;
    if (coords[0][0] > coords[1][0])
    {
        d_ = coords[0];
        coords[0] = coords[1];
        coords[1] = d_;
    }
    if (coords[0][0] > coords[2][0])
    {
        d_ = coords[0];
        coords[0] = coords[2];
        coords[2] = d_;
    }
    if (coords[1][0] > coords[2][0])
    {
        d_ = coords[1];
        coords[1] = coords[2];
        coords[2] = d_;
    }





    // x1= f[2][0]   f[2][1]
    // x2= f[1][0]   f[1][1]

     //(((f[1][0] - f[0][0]) == 0) ? f[0][1] : ((f[1][1] - f[0][1]) * (x - f[0][0]) / (f[1][0] - f[0][0]) + f[0][1])) lc

     //(((f[2][0] - f[0][0]) == 0) ? f[0][1] : ((f[2][1] - f[0][1]) * (x - f[0][0]) / (f[2][0] - f[0][0]) + f[0][1])) lr`

         //(((f[1][0] - f[2][0]) == 0) ? f[2][1] : ((f[1][1] - f[2][1]) * (x - f[2][0]) / (f[1][0] - f[2][0]) + f[2][1])) rc


    for (double x = coords[0][0]; x < coords[1][0]; x++)
    {
        SDL_RenderDrawLine(ren, x, (((coords[1][0] - coords[0][0]) == 0) ? coords[0][1] : ((coords[1][1] - coords[0][1]) * (x - coords[0][0]) / (coords[1][0] - coords[0][0]) + coords[0][1])), x, (((coords[2][0] - coords[0][0]) == 0) ? coords[0][1] : ((coords[2][1] - coords[0][1]) * (x - coords[0][0]) / (coords[2][0] - coords[0][0]) + coords[0][1])));
    }

    for (double x = coords[1][0]; x <= coords[2][0]; x++)
    {
        SDL_RenderDrawLine(ren, x, (((coords[1][0] - coords[2][0]) == 0) ? coords[2][1] : ((coords[1][1] - coords[2][1]) * (x - coords[2][0]) / (coords[1][0] - coords[2][0]) + coords[2][1])), x, (((coords[2][0] - coords[0][0]) == 0) ? coords[0][1] : ((coords[2][1] - coords[0][1]) * (x - coords[0][0]) / (coords[2][0] - coords[0][0]) + coords[0][1])));
    }
    /*
    for (double x = f[0][0]; x < f[1][0]; x++)
    {
        SDL_RenderDrawLine(ren, x, (((f[1][0] - f[0][0]) == 0) ? f[0][1] : ((f[1][1] - f[0][1]) * (x - f[0][0]) / (f[1][0] - f[0][0]) + f[0][1])), x, (((f[2][0] - f[0][0]) == 0) ? f[0][1] : ((f[2][1] - f[0][1]) * (x - f[0][0]) / (f[2][0] - f[0][0]) + f[0][1])));
    }

    for (double x = f[1][0]; x <= f[2][0]; x++)
    {
        SDL_RenderDrawLine(ren, x, (((f[1][0] - f[2][0]) == 0) ? f[2][1] : ((f[1][1] - f[2][1]) * (x - f[2][0]) / (f[1][0] - f[2][0]) + f[2][1])), x, (((f[2][0] - f[0][0]) == 0) ? f[0][1] : ((f[2][1] - f[0][1]) * (x - f[0][0]) / (f[2][0] - f[0][0]) + f[0][1])));
    }
    */






}
