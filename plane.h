


#pragma once
#include <iostream>

#include <SDL.h>

#include "base_polygone.h"

#include "template_functions.h"



using namespace std;



class Plane : public Base_polygone
    //������� - ��� ������ �����������
{
public:

 

    Plane(const Plane& polygone_copy);



    Plane();

    Plane& operator=(const Plane& right); 

    ~Plane();

   

    virtual void set_z() override;


    virtual void set_�olor(Color �olor_) override;
    virtual Color get_�olor() override;

    virtual void draw(SDL_Renderer* ren) override;

    void associate(double** plane_coord);


 
private:


    double a;
    double b;
    double c;



};




