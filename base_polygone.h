#pragma once
#include <iostream>

#include <SDL.h>

#include "template_functions.h"


using namespace std;



class Base_polygone
    //������� - ��� ������ �����������
{
public:

    double z;

    Base_polygone() {};

    virtual ~Base_polygone() {};

    virtual void set_z() = 0;



    virtual void set_�olor(Color �olor_) = 0;
    virtual Color get_�olor() = 0;



    virtual void draw(SDL_Renderer* ren) = 0;

protected:


    Color c;


};




