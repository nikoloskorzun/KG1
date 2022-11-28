
#pragma once
#include <iostream>

#include <SDL.h>

#include "polygone.h"


using namespace std;


Polygone::Polygone(const Polygone& polygone_copy)
{
    this->c = polygone_copy.c; 
    
    this->z = polygone_copy.z;
    this->pointer_vertex_1 = polygone_copy.pointer_vertex_1;
    this->pointer_vertex_2 = polygone_copy.pointer_vertex_2;
    this->pointer_vertex_3 = polygone_copy.pointer_vertex_3;



}

void Polygone::set_ñolor(Color ñolor_)
{
    this->c = ñolor_;
}

Color Polygone::get_ñolor()
{
    return this->c;
}


Polygone::Polygone()
{
    
    this->z = NULL;


    

    this->c.r = rand() % 256;
    this->c.g = rand() % 256;
    this->c.b = rand() % 256;
    this->c.a = 255;


}


Polygone& Polygone::operator=(const Polygone& right) {


    //#TODO 

    //ïðîâåðêà íà ñàìîïðèñâàèâàíèå
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

Polygone::~Polygone()
{


    return;

}


void Polygone::set_z()
{
    /*

    cout << pointer_vertex_1[0] << "; " << pointer_vertex_1[1] << "; " << pointer_vertex_1[2] << endl;
    cout << pointer_vertex_2[0] << "; " << pointer_vertex_2[1] << "; " << pointer_vertex_2[2] << endl;
    cout << pointer_vertex_3[0] << "; " << pointer_vertex_3[1] << "; " << pointer_vertex_3[2] << endl;
    */


    //z = (pointer_vertex_1[2] + pointer_vertex_2[2] + pointer_vertex_3[2]) / 3;
    //return;

    double az = pointer_vertex_1[2], bz = pointer_vertex_2[2], cz = pointer_vertex_3[2];


    double mz = (az + cz) / 2, pz = (az + bz) / 2;
    double kz = (bz + cz) / 2;


    z = (az + bz + cz + mz + pz + kz) / 6;

   // cout << z<< "   " << c.r <<":" << c.g <<":" << c.b << endl<<endl;

        return;







    /*
    
                A
        
            p
        B       Z   m
        
               k
                       C

    
    
    */

    
    if (bz != cz)
        this->z = (cz * mz - bz * pz) / (mz + cz - bz - pz);
    else
        if (az != bz)
            this->z = (bz * kz - az * mz) / (kz + bz - az - mz);
        else
            if (az != cz)
                this->z = (cz * kz - az * pz) / (kz + cz - az - pz);
            else
                this->z = az;






    //cout << az << " " << bz << " " << cz << "\n" << this->z << "\n";





    //
    //this->z = (f[0][2] + f[1][2] + f[2][2]) / 3;


}
void Polygone::associate(double* d1, double* d2, double* d3)
{
    this->pointer_vertex_1 = d1;
    this->pointer_vertex_2 = d2;
    this->pointer_vertex_3 = d3;
}



double* Polygone::get_vertex1()
{
    return this->pointer_vertex_1;
}
double* Polygone::get_vertex2()
{
    return this->pointer_vertex_2;
}
double* Polygone::get_vertex3()
{
    return this->pointer_vertex_3;
}


void  Polygone::draw(SDL_Renderer* ren)
{

    /*
    double a = f[0][1] * (f[1][2] - f[2][2]) + f[1][1] * (f[2][2] - f[0][2]) + f[2][1] * (f[0][2] - f[1][2]);
    double b = f[0][0] * (f[2][2] - f[1][2]) + f[1][0] * (f[0][2] - f[2][2]) + f[2][0] * (f[1][2] - f[0][2]);
    //double c = f[0][0] * (f[1][1] - f[2][1]) + f[1][0] * (f[2][1] - f[0][1]) + f[2][0] * (f[0][1] - f[1][1]);

    double x1 = (f[0][0] + f[1][0] + f[2][0]) / 3;
    double y1 = (f[0][1] + f[1][1] + f[2][1]) / 3;
    double x2 = x1 + a;
    double y2 = y1 + b;
    Íîðìàëü

   SDL_RenderDrawLine(ren, x1, y1, x2, y2);
   */


    SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, c.a);
    SDL_RenderDrawLine(ren, pointer_vertex_1[0], pointer_vertex_1[1], pointer_vertex_2[0], pointer_vertex_2[1]);
    SDL_RenderDrawLine(ren, pointer_vertex_1[0], pointer_vertex_1[1], pointer_vertex_3[0], pointer_vertex_3[1]);
    SDL_RenderDrawLine(ren, pointer_vertex_3[0], pointer_vertex_3[1], pointer_vertex_2[0], pointer_vertex_2[1]);

    //  return;

    

    double* d_;
    if (pointer_vertex_1[0] > pointer_vertex_2[0])
    {
        d_ = pointer_vertex_1;
        pointer_vertex_1 = pointer_vertex_2;
        pointer_vertex_2 = d_;
    }
    if (pointer_vertex_1[0] > pointer_vertex_3[0])
    {
        d_ = pointer_vertex_1;
        pointer_vertex_1 = pointer_vertex_3;
        pointer_vertex_3 = d_;
    }
    if (pointer_vertex_2[0] > pointer_vertex_3[0])
    {
        d_ = pointer_vertex_2;
        pointer_vertex_2 = pointer_vertex_3;
        pointer_vertex_3 = d_;
    }


    


    // x1= f[2][0]   f[2][1]
    // x2= f[1][0]   f[1][1]

     //(((f[1][0] - f[0][0]) == 0) ? f[0][1] : ((f[1][1] - f[0][1]) * (x - f[0][0]) / (f[1][0] - f[0][0]) + f[0][1])) lc

     //(((f[2][0] - f[0][0]) == 0) ? f[0][1] : ((f[2][1] - f[0][1]) * (x - f[0][0]) / (f[2][0] - f[0][0]) + f[0][1])) lr`

         //(((f[1][0] - f[2][0]) == 0) ? f[2][1] : ((f[1][1] - f[2][1]) * (x - f[2][0]) / (f[1][0] - f[2][0]) + f[2][1])) rc


    for (double x = pointer_vertex_1[0]; x < pointer_vertex_2[0]; x++)
    {
        SDL_RenderDrawLine(ren, x, (((pointer_vertex_2[0] - pointer_vertex_1[0]) == 0) ? pointer_vertex_1[1] : ((pointer_vertex_2[1] - pointer_vertex_1[1]) * (x - pointer_vertex_1[0]) / (pointer_vertex_2[0] - pointer_vertex_1[0]) + pointer_vertex_1[1])), x, (((pointer_vertex_3[0] - pointer_vertex_1[0]) == 0) ? pointer_vertex_1[1] : ((pointer_vertex_3[1] - pointer_vertex_1[1]) * (x - pointer_vertex_1[0]) / (pointer_vertex_3[0] - pointer_vertex_1[0]) + pointer_vertex_1[1])));
    }

    for (double x = pointer_vertex_2[0]; x <= pointer_vertex_3[0]; x++)
    {
        SDL_RenderDrawLine(ren, x, (((pointer_vertex_2[0] - pointer_vertex_3[0]) == 0) ? pointer_vertex_3[1] : ((pointer_vertex_2[1] - pointer_vertex_3[1]) * (x - pointer_vertex_3[0]) / (pointer_vertex_2[0] - pointer_vertex_3[0]) + pointer_vertex_3[1])), x, (((pointer_vertex_3[0] - pointer_vertex_1[0]) == 0) ? pointer_vertex_1[1] : ((pointer_vertex_3[1] - pointer_vertex_1[1]) * (x - pointer_vertex_1[0]) / (pointer_vertex_3[0] - pointer_vertex_1[0]) + pointer_vertex_1[1])));
    }
    /*
    for (double x = f[0][0]; x < f[1][0]; x++)
    {
        SDL_RenderDrawLine(ren, x, (((f[1][0] - f[0][0]) == 0) ? f[0][1] : ((f[1][1] - f[0][1]) * (x - f[0][0]) / (f[1][0] - f[0][0]) + f[0][1])), x, (((f[2][0] - f[0][0]) == 0) ? f[0][1] : ((f[2][1] - f[0][1]) * (x - f[0][0]) / (f[2][0] - f[0][0]) + f[0][1])));
    }

    for (double x = f[1][0]; x <= f[2][0]; x++)
    {
        SDL_RenderDrawLine(ren, x, (((f[1][0] - f[2][0]) == 0) ? f[2][1] : ((f[1][1] - f[2][1]) * (x - f[2][0]) / (f[1][0] - f[2][0]) + f[2][1])), x, (((f[2][0] - f[0][0]) == 0) ? f[0][1] : ((f[2][1] - f[0][1]) * (x - f[0][0]) / (f[2][0] - f[0][0]) + f[0][1])));
    }
    */


    
    


}
