#pragma once
#include <iostream>

#include <SDL.h>

#include "template_functions.h"
#include "base_polygone.h"


using namespace std;

//Самый плохой (слишком много допущений) класс

class Shadow_polygone : public Base_polygone
    //Теневой полигон - это многоугольник чаще треугольник но может быть 4-х и 5-ти угольник
    //логика хранения координат в теневом полигоне выбивается из логики хранения привычных координат. здесь мы не храним указатели на координаты а сразу храним координаты, потомучто так логичнее всего.
{
public:


    Shadow_polygone(const Shadow_polygone& polygone_copy);



    Shadow_polygone();

    Shadow_polygone& operator=(const Shadow_polygone& right);

    ~Shadow_polygone();

    virtual void set_z() override;

    virtual void set_сolor(Color сolor_) override;
    virtual Color get_сolor() override;

    void set_vertexes(size_t count, double** v);


    virtual void draw(SDL_Renderer* ren) override;

private:


    
    size_t count_of_vertex;

    double **coords;//5*3 always - bad code




};




