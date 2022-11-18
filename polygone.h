#pragma once
#include <iostream>

#include <SDL.h>

#include "base_polygone.h"

#include "template_functions.h"


using namespace std;



class Polygone : public Base_polygone
    //Полигон - это всегда треугольник
{
public:



    Polygone(const Polygone& polygone_copy);

    

    Polygone();
    
    Polygone& operator=(const Polygone& right);

    ~Polygone();

    virtual void set_z() override;


    void associate(double* d1, double* d2, double* d3);



    virtual void set_сolor(Color сolor_) override;
    virtual Color get_сolor() override;



    virtual void draw(SDL_Renderer* ren) override;

private:



    double *pointer_vertex_1;
    double *pointer_vertex_2;
    double *pointer_vertex_3;




};




