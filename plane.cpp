#pragma once

#include "plane.h"

using namespace std;





Plane::Plane(const Plane& polygone_copy)
{

    this->pointer_vertex_1 = polygone_copy.pointer_vertex_1;
    this->pointer_vertex_2 = polygone_copy.pointer_vertex_2;
    this->pointer_vertex_3 = polygone_copy.pointer_vertex_3;


    this->z = polygone_copy.z;
    this->c = polygone_copy.c;


}



    Plane::Plane()
    
    {


        this->z = NULL;
        this->c = {100, 100, 100, 255};
    }

    Plane& Plane::operator=(const Plane& right) {
        if (this == &right) {
            return *this;
        }

        this->pointer_vertex_1 = right.pointer_vertex_1;
        this->pointer_vertex_2 = right.pointer_vertex_2;
        this->pointer_vertex_3 = right.pointer_vertex_3;

        this->z = right.z;
        this->c = right.c;

        return *this;
    }

    Plane::~Plane()
    {

    }



    void Plane::set_z() 
    {
        z =( this->pointer_vertex_1[2] + this->pointer_vertex_2[2] + this->pointer_vertex_3[2])/3;
    }


     void Plane::set_ñolor(Color ñolor) 
     {
         this->c.r = 255;
         this->c.g = 255;
         this->c.b = 255;
         this->c.a = 255;
     }



     Color Plane::get_ñolor() 
     {
         return c;
     }

     void Plane::draw(SDL_Renderer* ren) 
     {
         SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, c.a);
         SDL_RenderClear(ren);
         //no
     }

    void Plane::associate(double** plane_coord) 
    
    {
        this->pointer_vertex_1 = plane_coord[0];
        this->pointer_vertex_2 = plane_coord[1];
        this->pointer_vertex_3 = plane_coord[2];
    }






