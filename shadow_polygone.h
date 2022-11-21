#pragma once
#include <iostream>

#include <SDL.h>

#include "template_functions.h"
#include "base_polygone.h"


using namespace std;



class Shadow_polygone : public Base_polygone
    //Теневой полигон - это многоугольник чаще треугольник но может быть 4-х и 5-ти угольник

{
public:


    Shadow_polygone(const Shadow_polygone& polygone_copy);



    Shadow_polygone();

    Shadow_polygone& operator=(const Shadow_polygone& right);

    ~Shadow_polygone();

    void set_z();



    void set_vertexes(size_t count, double** v);


    void draw(SDL_Renderer* ren);

private:


    
    size_t count_of_vertex;

    double* pointer_vertex_1;
    double* pointer_vertex_2;
    double* pointer_vertex_3;
    double* pointer_vertex_4;
    double* pointer_vertex_5;




};




