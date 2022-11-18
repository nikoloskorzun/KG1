#pragma once
#include <iostream>

#include <SDL.h>

#include "template_functions.h"


using namespace std;



class Shadow_polygone
    //Полигон - это всегда треугольник
{
public:

    double z;

    Shadow_polygone(const Shadow_polygone& polygone_copy);



    Shadow_polygone();

    Shadow_polygone& operator=(const Shadow_polygone& right);

    ~Shadow_polygone();

    void set_z();


    void associate(double* d1, double* d2, double* d3);




    void draw(SDL_Renderer* ren);

private:


    Color c;


    double* pointer_vertex_1;
    double* pointer_vertex_2;
    double* pointer_vertex_3;




};




