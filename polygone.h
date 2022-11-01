#pragma once
#include "lib.h"
using namespace std;
class Polygone
{
public:

    double z;

    Polygone(const Polygone& plygone_copy);

    

    Polygone();
    
    Polygone& operator=(const Polygone& right);

    ~Polygone();

    void set_z();
    void associate(double* d1, double* d2, double* d3);






    void draw(SDL_Renderer* ren);

private:
    double** f;
    uint32_t N;

    color c;






};




