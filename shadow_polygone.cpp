
#pragma once
#include <iostream>

#include <SDL.h>

#include "shadow_polygone.h"


using namespace std;






void Shadow_polygone::set_vertexes(size_t count, double** v)
{
    this->pointer_vertex_1 = v[0];
    this->pointer_vertex_2 = v[1];
    this->pointer_vertex_3 = v[2];

    this->count_of_vertex = count;



    switch (count)
    {
    case 5:
        this->pointer_vertex_5 = v[4];
    case 4:
        this->pointer_vertex_4 = v[3];
        break;

    }


}



Shadow_polygone::Shadow_polygone(const Shadow_polygone& polygone_copy)
{

    this->c = polygone_copy.c;



    this->z = polygone_copy.z;
    this->pointer_vertex_1 = polygone_copy.pointer_vertex_1;
    this->pointer_vertex_2 = polygone_copy.pointer_vertex_2;
    this->pointer_vertex_3 = polygone_copy.pointer_vertex_3;
    this->pointer_vertex_4 = polygone_copy.pointer_vertex_4;
    this->pointer_vertex_5 = polygone_copy.pointer_vertex_5;

    this->count_of_vertex = polygone_copy.count_of_vertex;



    //cout << "copy ERROR\n";

}



Shadow_polygone::Shadow_polygone()
{

    this->z = NULL;
    this->pointer_vertex_1 = NULL;
    this->pointer_vertex_2 = NULL;
    this->pointer_vertex_3 = NULL;
    this->pointer_vertex_4 = NULL;
    this->pointer_vertex_5 = NULL;

    this->count_of_vertex = 0;


    this->c.r =255;
    this->c.g = 255;
    this->c.b = 255;
    this->c.a = 255;


}


Shadow_polygone& Shadow_polygone::operator=(const Shadow_polygone& right) {



    //проверка на самоприсваивание
    if (this == &right) {
        return *this;
    }


    this->z = right.z;
    this->pointer_vertex_1 = right.pointer_vertex_1;
    this->pointer_vertex_2 = right.pointer_vertex_2;
    this->pointer_vertex_3 = right.pointer_vertex_3;
    this->pointer_vertex_4 = right.pointer_vertex_4;
    this->pointer_vertex_5 = right.pointer_vertex_5;


    this->count_of_vertex = right.count_of_vertex;




    this->c  = right.c;




    return *this;
}

Shadow_polygone::~Shadow_polygone()
{


    return;

}




void Shadow_polygone::set_z()
{
    /*

    cout << pointer_vertex_1[0] << "; " << pointer_vertex_1[1] << "; " << pointer_vertex_1[2] << endl;
    cout << pointer_vertex_2[0] << "; " << pointer_vertex_2[1] << "; " << pointer_vertex_2[2] << endl;
    cout << pointer_vertex_3[0] << "; " << pointer_vertex_3[1] << "; " << pointer_vertex_3[2] << endl;
    */


    //z = (pointer_vertex_1[2] + pointer_vertex_2[2] + pointer_vertex_3[2]) / 3;
    //return;

    if (!count_of_vertex)
        return;

    double az = pointer_vertex_1[2], bz = pointer_vertex_2[2], cz = pointer_vertex_3[2];


    double mz = (az + cz) / 2, pz = (az + bz) / 2;
    double kz = (bz + cz) / 2;


    z = (az + bz + cz + mz + pz + kz) / 6;

    // cout << z<< "   " << c.r <<":" << c.g <<":" << c.b << endl<<endl;

    return;





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

void Shadow_polygone::set_сolor(Color сolor)
{
    this->c.r = 255;
    this->c.g = 255;
    this->c.b = 255;
    this->c.a = 255;
}



Color Shadow_polygone::get_сolor()
{
    return c;
}

void  Shadow_polygone::draw(SDL_Renderer* ren)
{

    /*
    double a = f[0][1] * (f[1][2] - f[2][2]) + f[1][1] * (f[2][2] - f[0][2]) + f[2][1] * (f[0][2] - f[1][2]);
    double b = f[0][0] * (f[2][2] - f[1][2]) + f[1][0] * (f[0][2] - f[2][2]) + f[2][0] * (f[1][2] - f[0][2]);
    //double c = f[0][0] * (f[1][1] - f[2][1]) + f[1][0] * (f[2][1] - f[0][1]) + f[2][0] * (f[0][1] - f[1][1]);

    double x1 = (f[0][0] + f[1][0] + f[2][0]) / 3;
    double y1 = (f[0][1] + f[1][1] + f[2][1]) / 3;
    double x2 = x1 + a;
    double y2 = y1 + b;
    Нормаль

   SDL_RenderDrawLine(ren, x1, y1, x2, y2);
   */
    if (this->count_of_vertex != 3)
        return;
    

    if(0)
        for(int i=0; i<3; i++)
    { 
        if (pointer_vertex_1[i] < 0 || pointer_vertex_1[i]>5000)
            return;
        if (pointer_vertex_2[i] < 0 || pointer_vertex_2[i]>5000)
            return;
        if (pointer_vertex_3[i] < 0 || pointer_vertex_3[i]>5000)
            return;        
        

    }

    cout << "<"<<pointer_vertex_1[0] << " " << pointer_vertex_1[1] << " " << pointer_vertex_1[2] << endl;
    cout << pointer_vertex_2[0] << " " << pointer_vertex_2[1] << " " << pointer_vertex_2[2] << endl;
    cout << pointer_vertex_3[0] << " " << pointer_vertex_3[1] << " " << pointer_vertex_3[2]<<">" << endl;

    SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, c.a);
    SDL_RenderDrawLine(ren, pointer_vertex_1[0], pointer_vertex_1[1], pointer_vertex_2[0], pointer_vertex_2[1]);
    SDL_RenderDrawLine(ren, pointer_vertex_1[0], pointer_vertex_1[1], pointer_vertex_3[0], pointer_vertex_3[1]);
    SDL_RenderDrawLine(ren, pointer_vertex_3[0], pointer_vertex_3[1], pointer_vertex_2[0], pointer_vertex_2[1]);

    //
    return;



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
