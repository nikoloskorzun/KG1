#pragma once




#include "lib.h"



using namespace std;





class Figure {






public:
   



public:


    Figure();

    void painter_algoritm(SDL_Renderer* ren);

    void set(size_t n, double** coords, size_t** info, size_t len);


    Figure(size_t n, double** coords, size_t** info, size_t len);

    ~Figure();
   

    void move_up();
    void move_down();
    void move_left();
    void move_right();

    void rotate_y_positive();
    void rotate_y_negative();
    void rotate_x_positive();
    void rotate_x_negative();
    void rotate_z_positive();
    void rotate_z_negative();

    void scale_up();
    void scale_down();



private:



    double** m_move;
    double** m_rotate_x;
    double** m_rotate_y;
    double** m_rotate_z;
    double** m_scale;

    double** f;

    size_t N;

    size_t M; // = 4 always

    size_t Polygone_count;

    Polygone* Polygones;


    double DX;
    double DY;
    double DZ;

    double ANGLE;

    double SCALE_FACTOR;

    

    void draw(SDL_Renderer* ren);


    inline void create_m_move();
    inline void create_m_scale();

    inline void create_m_rotate_x();
    inline void create_m_rotate_y();
    inline void create_m_rotate_z();


    inline void rotate_x(double k);
    inline void rotate_y(double k);
    inline void rotate_z(double k);

    inline void scaling(double k);

    void multing(double** lin, double** matrix);

};
