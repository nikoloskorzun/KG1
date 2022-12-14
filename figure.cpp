
#pragma once
#include <iostream>


#include "figure.h"



#include "polygone.h"

#include "template_functions.cpp"


using namespace std;




void Figure::create_projection()
{
    //??????? ?? Y ? X
    register size_t i;
    register size_t j;

    for (i = 0; i < this->N; i++)
        for (j = 0; j < this->M; j++)
        {
            this->f_proj[i][j] = f[i][j];
        }

    multing(f_proj, m_proj);



}


Figure::Figure()
{

    this->f = NULL;
    this->m_move = NULL;
    this->m_scale = NULL;

    this->m_rotate_x = NULL;
    this->m_rotate_y = NULL;
    this->m_rotate_z = NULL;



    this->N = NULL;
    this->M = NULL;


    this->DX = NULL;
    this->DY = NULL;
    this->DZ = NULL;

    this->ANGLE = NULL;
    this->SCALE_FACTOR = NULL;


}

void Figure::associate_figure_with_polygones(Base_polygone** polygone_array, size_t** rule, size_t polugones_count, size_t first_elem_pos)
{

    Polygone* p;
    for (size_t i = 0; i < polugones_count; i++)
    {
        p = new Polygone;

        p->associate(this->f[rule[i][0]], this->f[rule[i][1]], this->f[rule[i][2]]);

        polygone_array[i + first_elem_pos] = p;
            

    }

}
void Figure::associate_figure_proj_with_polygones(Base_polygone** polygone_array, size_t** rule, size_t polugones_count, size_t first_elem_pos)
{
    Polygone* p;
    Color c = { 255,255,255,255 };
    for (size_t i = 0; i < polugones_count; i++)
    {
        p = new Polygone;

        p->associate(this->f_proj[rule[i][0]], this->f_proj[rule[i][1]], this->f_proj[rule[i][2]]);
        p->set_?olor(c);
        polygone_array[i + first_elem_pos] = p;


    }

}




void Figure::set(size_t n, double** coords)
/*

*/
{
    register size_t i;
    register size_t j;

    this->DX = 5;
    this->DY = 5;
    this->DZ = 5;

    this->ANGLE = M_PI / 36;
    this->SCALE_FACTOR = 1.1;


    //allocate memory for arr, and fill this array
    this->N = n;
    this->M = 4;

    this->f = allocate_memory_for_N_M_array<double>(this->N, this->M);

    create_m_move();
    create_m_scale();

    create_m_rotate_x();
    create_m_rotate_y();
    create_m_rotate_z();


    create_m_projection();


    for (i = 0; i < this->N; i++)
        for (j = 0; j < this->M; j++)
        {
            this->f[i][j] = coords[i][j];
        }

    this->f_proj = allocate_memory_for_N_M_array<double>(this->N, this->M);



}


Figure::Figure(size_t n, double** coords)
{
    this->set(n, coords);
}

Figure::~Figure()
{


    if (this->f)
    {
        free_memory_for_N_M_array<double>(this->f, this->N, this->M);
    }
    if (this->f_proj)
    {
        free_memory_for_N_M_array<double>(this->f_proj, this->N, this->M);
    }

    if (this->m_move)
    {
        free_memory_for_N_M_array<double>(this->m_move, this->M, this->M);
    }
    if (this->m_scale)
    {
        free_memory_for_N_M_array<double>(this->m_scale, this->M, this->M);
    }

    if (this->m_rotate_x)
    {
        free_memory_for_N_M_array<double>(this->m_rotate_x, this->M, this->M);
    }


    if (this->m_rotate_y)
    {
        free_memory_for_N_M_array<double>(this->m_rotate_y, this->M, this->M);
    }

    if (this->m_rotate_z)
    {
        free_memory_for_N_M_array<double>(this->m_rotate_z, this->M, this->M);
    }

    if (this->m_proj)
    {
        free_memory_for_N_M_array<double>(this->m_proj, this->M, this->M);
    }


   

}




void Figure::move_up()
{

    m_move[3][0] = 0; // 
    m_move[3][1] = -this->DY; // 
    m_move[3][2] = 0; //


    multing(this->f, m_move);
}
void Figure::move_down()
{
    m_move[3][0] = 0; // 
    m_move[3][1] = this->DY; // 
    m_move[3][2] = 0; //


    multing(this->f, m_move);
}
void Figure::move_left()
{
    m_move[3][0] = -this->DX; // 
    m_move[3][1] = 0; // 
    m_move[3][2] = 0; //


    multing(this->f, m_move);
}
void Figure::move_right()
{
    m_move[3][0] = this->DX; // 
    m_move[3][1] = 0; // 
    m_move[3][2] = 0; //


    multing(this->f, m_move);
}
void Figure::move_forward()
{
    m_move[3][0] = 0; // 
    m_move[3][1] = 0; // 
    m_move[3][2] = -this->DZ; //


    multing(this->f, m_move);
}
void Figure::move_back()
{
    m_move[3][0] = 0; // 
    m_move[3][1] = 0; // 
    m_move[3][2] = this->DZ; //


    multing(this->f, m_move);
}






void Figure::rotate_y_positive()
{
    rotate_y(1);
}
void Figure::rotate_y_negative()
{
    rotate_y(-1);
}
void Figure::rotate_x_positive()
{
    rotate_x(1);
}
void Figure::rotate_x_negative()
{
    rotate_x(-1);
}
void Figure::rotate_z_positive()
{
    rotate_z(1);
}
void Figure::rotate_z_negative()
{
    rotate_z(-1);
}




void Figure::scale_up()
{
    scaling(0);
}

void Figure::scale_down()
{
    scaling(-1);

}

inline void Figure::create_m_move()
{
    this->m_move = allocate_memory_for_N_M_array<double>(this->M, this->M);

    this->m_move[0][0] = 1;
    this->m_move[0][1] = 0;
    this->m_move[0][2] = 0;
    this->m_move[0][3] = 0;

    this->m_move[1][0] = 0;
    this->m_move[1][1] = 1;
    this->m_move[1][2] = 0;
    this->m_move[1][3] = 0;

    this->m_move[2][0] = 0;
    this->m_move[2][1] = 0;
    this->m_move[2][2] = 1;
    this->m_move[2][3] = 0;

    this->m_move[3][3] = 1;

}


inline void Figure::create_m_scale()
{

    this->m_scale = allocate_memory_for_N_M_array<double>(this->M, this->M);

    this->m_scale[0][1] = 0;
    this->m_scale[0][2] = 0;
    this->m_scale[0][3] = 0;

    this->m_scale[1][0] = 0;
    this->m_scale[1][2] = 0;
    this->m_scale[1][3] = 0;

    this->m_scale[2][0] = 0;
    this->m_scale[2][1] = 0;
    this->m_scale[2][3] = 0;

    this->m_scale[3][3] = 1;

}


inline void Figure::create_m_rotate_x()
{

    this->m_rotate_x = allocate_memory_for_N_M_array<double>(this->M, this->M);

    this->m_rotate_x[0][0] = 1;
    this->m_rotate_x[0][1] = 0;
    this->m_rotate_x[0][2] = 0;
    this->m_rotate_x[0][3] = 0;

    this->m_rotate_x[1][0] = 0;
    this->m_rotate_x[1][1] = cos(this->ANGLE);
    this->m_rotate_x[1][3] = 0;

    this->m_rotate_x[2][0] = 0;
    this->m_rotate_x[2][2] = cos(this->ANGLE);
    this->m_rotate_x[2][3] = 0;

    this->m_rotate_x[3][0] = 0;
    this->m_rotate_x[3][3] = 1;

}
inline void Figure::create_m_rotate_y()
{

    this->m_rotate_y = allocate_memory_for_N_M_array<double>(this->M, this->M);

    this->m_rotate_y[0][0] = cos(this->ANGLE);
    this->m_rotate_y[0][1] = 0;
    this->m_rotate_y[0][3] = 0;

    this->m_rotate_y[1][0] = 0;
    this->m_rotate_y[1][1] = 1;
    this->m_rotate_y[1][2] = 0;
    this->m_rotate_y[1][3] = 0;

    this->m_rotate_y[2][1] = 0;
    this->m_rotate_y[2][2] = cos(this->ANGLE);
    this->m_rotate_y[2][3] = 0;

    this->m_rotate_y[3][1] = 0;
    this->m_rotate_y[3][3] = 1;

}
inline void Figure::create_m_rotate_z()
{

    this->m_rotate_z = allocate_memory_for_N_M_array<double>(this->M, this->M);

    this->m_rotate_z[0][0] = cos(this->ANGLE);
    this->m_rotate_z[0][2] = 0;
    this->m_rotate_z[0][3] = 0;

    this->m_rotate_z[1][1] = cos(this->ANGLE);
    this->m_rotate_z[1][2] = 0;
    this->m_rotate_z[1][3] = 0;

    this->m_rotate_z[2][0] = 0;
    this->m_rotate_z[2][1] = 0;
    this->m_rotate_z[2][2] = 1;
    this->m_rotate_z[2][3] = 0;

    this->m_rotate_z[3][2] = 0;
    this->m_rotate_z[3][3] = 1;

}

inline void Figure::create_m_projection()
{
    this->m_proj = allocate_memory_for_N_M_array<double>(this->M, this->M);

    this->m_proj[0][0] = 0.7;
    this->m_proj[0][1] = -0.4;
    this->m_proj[0][2] = 0;
    this->m_proj[0][3] = 0;

    this->m_proj[1][0] = 0;
    this->m_proj[1][1] = 0.8;
    this->m_proj[1][2] = 0;
    this->m_proj[1][3] = 0;

    this->m_proj[2][0] = 0.7;
    this->m_proj[2][1] = 0.4;
    this->m_proj[2][2] = 1;
    this->m_proj[2][3] = 0;
    
    this->m_proj[3][0] = 0;
    this->m_proj[3][1] = 0;
    this->m_proj[3][2] = 0;
    this->m_proj[3][3] = 1;

}






//??????? ???????? ?????? ??? X
inline void Figure::rotate_x(double k)
{
    register double yc = 0.0;
    register double zc = 0.0;
    register size_t i;
    for (i = 0; i < this->N; i++)
    {
        yc += this->f[i][1];
    }
    yc = yc / this->N;
    for (i = 0; i < this->N; i++)
    {
        zc += this->f[i][2];
    }
    zc = zc / this->N;


    this->m_rotate_x[1][2] = sin(k * this->ANGLE);
    this->m_rotate_x[2][1] = -sin(k * this->ANGLE);

    this->m_rotate_x[3][1] = yc * (1 - cos(this->ANGLE)) + zc * sin(k * this->ANGLE);
    this->m_rotate_x[3][2] = zc * (1 - cos(this->ANGLE)) - yc * sin(k * this->ANGLE);

    multing(this->f, this->m_rotate_x);


}

//??????? ???????? ?????? ??? Y
inline void Figure::rotate_y(double k)
{
    register double xc = 0.0;
    register double zc = 0.0;
    register size_t i;

    for (i = 0; i < this->N; i++)
    {
        xc += this->f[i][0];
    }
    xc = xc / this->N;
    for (i = 0; i < this->N; i++)
    {
        zc += this->f[i][2];
    }
    zc = zc / this->N;



    this->m_rotate_y[0][2] = -sin(k * this->ANGLE);

    this->m_rotate_y[2][0] = sin(k * this->ANGLE);

    this->m_rotate_y[3][0] = xc * (1 - cos(this->ANGLE)) - zc * sin(k * this->ANGLE);

    this->m_rotate_y[3][2] = zc * (1 - cos(this->ANGLE)) + xc * sin(k * this->ANGLE);


    multing(this->f, this->m_rotate_y);

}

//??????? ???????? ?????? ??? Z
inline void Figure::rotate_z(double k)
{
    register double xc = 0.0;
    register double yc = 0.0;
    register size_t i;
    for (i = 0; i < this->N; i++)
    {
        xc += this->f[i][0];
    }
    xc = xc / this->N;
    for (i = 0; i < this->N; i++)
    {
        yc += this->f[i][1];
    }
    yc = yc / this->N;



    this->m_rotate_z[0][1] = sin(k * this->ANGLE);
    this->m_rotate_z[1][0] = -sin(k * this->ANGLE);
    this->m_rotate_z[3][0] = xc * (1 - cos(this->ANGLE)) + yc * sin(k * this->ANGLE);
    this->m_rotate_z[3][1] = yc * (1 - cos(this->ANGLE)) - xc * sin(k * this->ANGLE);



    multing(this->f, this->m_rotate_z);


}





inline void Figure::scaling(double k)
{
    register double xc = 0.0;
    register double yc = 0.0;
    register double zc = 0.0;
    register size_t i;
    for (i = 0; i < this->N; i++)
    {
        xc += this->f[i][0];
    }
    xc = xc / this->N;
    for (i = 0; i < this->N; i++)
    {
        yc += this->f[i][1];
    }
    yc = yc / this->N;
    for (i = 0; i < this->N; i++)
    {
        zc += this->f[i][2];
    }
    zc = zc / this->N;


    double scale_koeff = (k == 0) ? (this->SCALE_FACTOR) : (1 / this->SCALE_FACTOR);




    this->m_scale[3][0] = xc * (1 - scale_koeff);
    this->m_scale[3][1] = yc * (1 - scale_koeff);
    this->m_scale[3][2] = zc * (1 - scale_koeff);


    this->m_scale[0][0] = scale_koeff;
    this->m_scale[1][1] = scale_koeff;
    this->m_scale[2][2] = scale_koeff;



    multing(this->f, this->m_scale); //????????? ??????? ??????? ?? ??????? ???????????????
}



void Figure::multing(double** lin, double** matrix)
{

    double** res = allocate_memory_for_N_M_array<double>(this->N, this->M);

    register size_t i;
    register size_t j;
    register size_t k;

    for (i = 0; i < this->N; i++)
        for (j = 0; j < this->M; j++)
            res[i][j] = 0;


    for (i = 0; i < this->N; i++)
    {
        for (j = 0; j < this->M; j++)
        {
            for (k = 0; k < this->M; k++)
            {
                res[i][j] += (lin[i][k] * matrix[k][j]);
            }
        }
    }

    //return res
    for (i = 0; i < this->N; i++)
    {
        for (j = 0; j < this->M; j++)
        {
            lin[i][j] = res[i][j];
        }
    }

    free_memory_for_N_M_array<double>(res, this->N, this->M);
    return;

}



