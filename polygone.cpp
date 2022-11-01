#include "lib.h"

using namespace std;


Polygone::Polygone(const Polygone& plygone_copy)
{
    cout << "copy ERROR\n";

}

Polygone::Polygone()
{
    this->N = 3;
    this->z = NULL;
    this->f = new double* [this->N];

    this->c.r = rand() % 255;
    this->c.g = rand() % 255;
    this->c.b = rand() % 255;
    this->c.a = 255;


}


Polygone& Polygone::operator=(const Polygone& right) {
    //проверка на самоприсваивание
    if (this == &right) {
        return *this;
    }

    this->N = right.N;
    this->z = right.z;

    this->f = new double* [this->N];

    this->f[0] = right.f[0];

    this->f[1] = right.f[1];

    this->f[2] = right.f[2];

    this->c.r = right.c.r;
    this->c.g = right.c.g;
    this->c.b = right.c.b;
    this->c.a = right.c.a;


    return *this;
}

Polygone::~Polygone()
{


    delete[] this->f;

}


void Polygone::set_z()
{



    double az = f[0][2], bz = f[1][2], cz = f[2][2];


    double mz = (az + cz) / 2, pz = (az + bz) / 2;
    double kz = (bz + cz) / 2;




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






    cout << az << " " << bz << " " << cz << "\n" << this->z << "\n";





    //
    //this->z = (f[0][2] + f[1][2] + f[2][2]) / 3;


}
void Polygone::associate(double* d1, double* d2, double* d3)
{
    f[0] = d1;
    f[1] = d2;
    f[2] = d3;


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
    Ќормаль

   SDL_RenderDrawLine(ren, x1, y1, x2, y2);
   */


    SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, c.a);

    //


    double* d_;
    if (f[0][0] > f[1][0])
    {
        d_ = f[0];
        f[0] = f[1];
        f[1] = d_;
    }
    if (f[0][0] > f[2][0])
    {
        d_ = f[0];
        f[0] = f[2];
        f[2] = d_;
    }
    if (f[1][0] > f[2][0])
    {
        d_ = f[1];
        f[1] = f[2];
        f[2] = d_;
    }


    


    // x1= f[2][0]   f[2][1]
    // x2= f[1][0]   f[1][1]

     //(((f[1][0] - f[0][0]) == 0) ? f[0][1] : ((f[1][1] - f[0][1]) * (x - f[0][0]) / (f[1][0] - f[0][0]) + f[0][1])) lc

     //(((f[2][0] - f[0][0]) == 0) ? f[0][1] : ((f[2][1] - f[0][1]) * (x - f[0][0]) / (f[2][0] - f[0][0]) + f[0][1])) lr`

         //(((f[1][0] - f[2][0]) == 0) ? f[2][1] : ((f[1][1] - f[2][1]) * (x - f[2][0]) / (f[1][0] - f[2][0]) + f[2][1])) rc

    for (double x = f[0][0]; x < f[1][0]; x++)
    {
        SDL_RenderDrawLine(ren, x, (((f[1][0] - f[0][0]) == 0) ? f[0][1] : ((f[1][1] - f[0][1]) * (x - f[0][0]) / (f[1][0] - f[0][0]) + f[0][1])), x, (((f[2][0] - f[0][0]) == 0) ? f[0][1] : ((f[2][1] - f[0][1]) * (x - f[0][0]) / (f[2][0] - f[0][0]) + f[0][1])));
    }

    for (double x = f[1][0]; x <= f[2][0]; x++)
    {
        SDL_RenderDrawLine(ren, x, (((f[1][0] - f[2][0]) == 0) ? f[2][1] : ((f[1][1] - f[2][1]) * (x - f[2][0]) / (f[1][0] - f[2][0]) + f[2][1])), x, (((f[2][0] - f[0][0]) == 0) ? f[0][1] : ((f[2][1] - f[0][1]) * (x - f[0][0]) / (f[2][0] - f[0][0]) + f[0][1])));
    }



    return;


    /*
                double gety(double x, double x1, double y1, double x2, double y2)

                    (((x2 - x1) == 0)?y1:((y2 - y1) * (x - x1) / (x2 - x1) + y1))




                void swap(point * a, point * b)
                {
                    point t = *a;
                    *a = *b;
                    *b = t;

                }



                void fill(double** lin, SDL_Renderer * render)
                {
                    point l, r, c;
                    l.x = (lin[0][0]);
                    l.y = (lin[0][1]);
                    r.x = (lin[1][0]);
                    r.y = (lin[1][1]);
                    c.x = (lin[2][0]);
                    c.y = (lin[2][1]);



                    if (l.x > c.x)
                        swap(&l, &c);
                    if (l.x > r.x)
                        swap(&l, &r);
                    if (c.x > r.x)
                        swap(&c, &r);




                }



                */










                //

               //cout << f[0][0] << " " << f[0][1] << endl;
               //cout << f[1][0] << " " << f[1][1] << endl;
               //cout << f[2][0] << " " << f[2][1] << endl;
               //cout << endl;
    /*
    * //////
    if (f[0][1] > f[1][1])
    {
        d_ = &f[0];
        *f[0] = *f[1];
        f[1] = *d_;
}
    if (f[0][1] > f[2][1])
    {
        d_ = &f[0];
        *f[0] = *f[2];
        f[2] = *d_;
}
    if (f[1][1] > f[2][1])
    { 
        d_ = &f[1];
        *f[1] = *f[2];
        f[2] = *d_;
    }
    */
    //cout << f[0][0] << " " << f[0][1] << endl;
    //cout << f[1][0] << " " << f[1][1] << endl;
    //cout << f[2][0] << " " << f[2][1] << endl;
    //cout << endl<<endl;

    register double iter;

    /*

            3

       ~2       ~2

            1


    */



    register double temp_value13 = (f[2][0] == f[0][0]) ? (0) : (f[2][0] - f[0][0]) / (f[2][1] - f[0][1]);
    register double temp_value12 = (f[1][0] == f[0][0]) ? (0) : (f[1][0] - f[0][0]) / (f[1][1] - f[0][1]);
    register double temp_value23 = (f[2][0] == f[1][0]) ? (0) : (f[2][0] - f[1][0]) / (f[2][1] - f[1][1]);


    SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, c.a);


    for (iter = f[0][1]; iter < f[1][1]; iter += 1)
    {
        SDL_RenderDrawLine(ren, (f[2][0] == f[0][0]) ? (f[0][0]) : ((iter - f[0][1]) * temp_value13 + f[0][0]), iter, (f[1][0] == f[0][0]) ? (f[0][0]) : ((iter - f[0][1]) * temp_value12 + f[0][0]), iter);

    }

    for (iter = f[1][1]; iter <= f[2][1]; iter += 1)
    {
        SDL_RenderDrawLine(ren, (f[2][0] == f[0][0]) ? (f[0][0]) : ((iter - f[0][1]) * temp_value13 + f[0][0]), iter, (f[2][0] == f[1][0]) ? (f[2][0]) : ((iter - f[2][1]) * temp_value23 + f[1][0]), iter);

    }




    //SDL_RenderDrawLine(ren, f[0][0], f[0][1], f[1][0], f[1][1]);
    //SDL_RenderDrawLine(ren, f[0][0], f[0][1], f[2][0], f[2][1]);
    //SDL_RenderDrawLine(ren, f[2][0], f[2][1], f[1][0], f[1][1]);

}
