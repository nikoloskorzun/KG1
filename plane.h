


#pragma once
#include <iostream>

#include <SDL.h>

#include "base_polygone.h"

#include "template_functions.h"



using namespace std;



class Plane : public Base_polygone
    //Полигон - это всегда треугольник
{
public:

 

    Plane(const Plane& polygone_copy);



    Plane();

    Plane& operator=(const Plane& right); 

    ~Plane();

   

    virtual void set_z() override;


    virtual void set_сolor(Color сolor_) override;
    virtual Color get_сolor() override;

    virtual void draw(SDL_Renderer* ren) override;

    void associate(double** plane_coord);


 
private:


    double a;
    double b;
    double c;



};




