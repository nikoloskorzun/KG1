#pragma once
#include <iostream>

#include "polygone.h"
using namespace std;


// Класс фигуры чистая математика без использования sdl и прочего...


class Figure {





public:

    Figure();

    void set(size_t n, double** coords);


    Figure(size_t n, double** coords);

    ~Figure();
   
    void associate_figure_with_polygones(Base_polygone** polygone_array, size_t **rule, size_t polugones_count, size_t first_elem_pos = 0);
    void associate_figure_proj_with_polygones(Polygone* polygone_array, size_t **rule, size_t polugones_count, size_t first_elem_pos = 0);

    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void move_forward();
    void move_back();


    void rotate_y_positive();
    void rotate_y_negative();
    void rotate_x_positive();
    void rotate_x_negative();
    void rotate_z_positive();
    void rotate_z_negative();

    void scale_up();
    void scale_down();

    void create_projection();

    void set_DX(double offset = 5);
    void set_DY(double offset = 5);
    void set_DZ(double offset = 5);



private:


    double** f_proj;



    double** m_move;
    double** m_rotate_x;
    double** m_rotate_y;
    double** m_rotate_z;
    double** m_scale;
    double** m_proj;

    double** f;

    size_t N;

    size_t M; // = 4 always

    double DX;
    double DY;
    double DZ;

    double ANGLE;

    double SCALE_FACTOR;

    

    inline void create_m_move();
    inline void create_m_scale();

    inline void create_m_rotate_x();
    inline void create_m_rotate_y();
    inline void create_m_rotate_z();
    
    inline void create_m_projection();


    inline void rotate_x(double k);
    inline void rotate_y(double k);
    inline void rotate_z(double k);

    inline void scaling(double k);

    void multing(double** lin, double** matrix);

};
