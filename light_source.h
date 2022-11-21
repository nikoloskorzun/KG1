


#pragma once
#include <iostream>

#include <SDL.h>




#include "base_polygone.h"
#include "template_functions.h"

using namespace std;



class Light_source: public Base_polygone
    //������� - ��� ������ �����������
{
public:



    Light_source(const Light_source& polygone_copy);



    Light_source();

    Light_source& operator=(const Light_source& right);

    ~Light_source();



    virtual void set_z() override;


    virtual void set_�olor(Color �olor_) override;


    virtual Color get_�olor() override;

    virtual void draw(SDL_Renderer* ren) override;

    void associate(double** l_source);


private:

    double** l;


};




