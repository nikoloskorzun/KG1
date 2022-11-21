


#pragma once
#include <iostream>

#include <SDL.h>




#include "base_polygone.h"
#include "template_functions.h"

using namespace std;



class Light_source: public Base_polygone
    //Полигон - это всегда треугольник
{
public:



    Light_source(const Light_source& polygone_copy);



    Light_source();

    Light_source& operator=(const Light_source& right);

    ~Light_source();



    virtual void set_z() override;


    virtual void set_сolor(Color сolor_) override;


    virtual Color get_сolor() override;

    virtual void draw(SDL_Renderer* ren) override;

    void associate(double** l_source);


private:

    double** l;


};




