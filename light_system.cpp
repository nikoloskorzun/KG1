#pragma once

#include "light_system.h"



//#include "template_functions.cpp"


inline void Light_system::create_m_move() 
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

inline void Light_system::create_m_rotate_x() 
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
inline void Light_system::create_m_rotate_y() 
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
inline void Light_system::create_m_rotate_z() 
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




inline void Light_system::rotate_x(double k, size_t number_of_plane) {
    register double yc = 0.0;
    register double zc = 0.0;
    register size_t i;
    for (i = 0; i < this->N; i++)
    {
        yc += this->planes[number_of_plane][i][1];
    }
    yc = yc / this->N;
    for (i = 0; i < this->N; i++)
    {
        zc += this->planes[number_of_plane][i][2];
    }
    zc = zc / this->N;


    this->m_rotate_x[1][2] = sin(k * this->ANGLE);
    this->m_rotate_x[2][1] = -sin(k * this->ANGLE);

    this->m_rotate_x[3][1] = yc * (1 - cos(this->ANGLE)) + zc * sin(k * this->ANGLE);
    this->m_rotate_x[3][2] = zc * (1 - cos(this->ANGLE)) - yc * sin(k * this->ANGLE);

    multing(planes[number_of_plane], this->m_rotate_x);

}
inline void Light_system::rotate_y(double k, size_t number_of_plane) {
    register double xc = 0.0;
    register double zc = 0.0;
    register size_t i;

    for (i = 0; i < this->N; i++)
    {
        xc += this->planes[number_of_plane][i][0];
    }
    xc = xc / this->N;
    for (i = 0; i < this->N; i++)
    {
        zc += this->planes[number_of_plane][i][2];
    }
    zc = zc / this->N;



    this->m_rotate_y[0][2] = -sin(k * this->ANGLE);

    this->m_rotate_y[2][0] = sin(k * this->ANGLE);

    this->m_rotate_y[3][0] = xc * (1 - cos(this->ANGLE)) - zc * sin(k * this->ANGLE);

    this->m_rotate_y[3][2] = zc * (1 - cos(this->ANGLE)) + xc * sin(k * this->ANGLE);


    multing(this->planes[number_of_plane], this->m_rotate_y);
}
inline void Light_system::rotate_z(double k, size_t number_of_plane) {
    register double xc = 0.0;
    register double yc = 0.0;
    register size_t i;
    for (i = 0; i < this->N; i++)
    {
        xc += this->planes[number_of_plane][i][0];
    }
    xc = xc / this->N;
    for (i = 0; i < this->N; i++)
    {
        yc += this->planes[number_of_plane][i][1];
    }
    yc = yc / this->N;



    this->m_rotate_z[0][1] = sin(k * this->ANGLE);
    this->m_rotate_z[1][0] = -sin(k * this->ANGLE);
    this->m_rotate_z[3][0] = xc * (1 - cos(this->ANGLE)) + yc * sin(k * this->ANGLE);
    this->m_rotate_z[3][1] = yc * (1 - cos(this->ANGLE)) - xc * sin(k * this->ANGLE);



    multing(this->planes[number_of_plane], this->m_rotate_z);
}


void Light_system::move_up_plane(size_t choice)
{
    m_move[3][0] = 0; // 
    m_move[3][1] = -this->DY; // 
    m_move[3][2] = 0; //


    multing(this->planes[choice], m_move);
}
void Light_system::move_down_plane(size_t choice)
{
    m_move[3][0] = 0; // 
    m_move[3][1] = this->DY; // 
    m_move[3][2] = 0; //


    multing(this->planes[choice], m_move);

}
void Light_system::move_left_plane(size_t choice)
{
    m_move[3][0] = -this->DX; // 
    m_move[3][1] = 0; // 
    m_move[3][2] = 0; //


    multing(this->planes[choice], m_move);

}
void Light_system::move_right_plane(size_t choice)
{
    m_move[3][0] = this->DX; // 
    m_move[3][1] = 0; // 
    m_move[3][2] = 0; //


    multing(this->planes[choice], m_move);

}
void Light_system::move_forward_plane(size_t choice)
{
    m_move[3][0] = 0; // 
    m_move[3][1] = 0; // 
    m_move[3][2] = -this->DZ; //


    multing(this->planes[choice], m_move);


}
void Light_system::move_back_plane(size_t choice)
{
    m_move[3][0] = 0; // 
    m_move[3][1] = 0; // 
    m_move[3][2] = this->DZ; //


    multing(this->planes[choice], m_move);


}



void Light_system::move_up_light()
{
    this->light_point[0][1] -= this->DY;
}
void Light_system::move_down_light()
{
    this->light_point[0][1] += this->DY;
}
void Light_system::move_left_light()
{
    this->light_point[0][0] -= this->DX;
}
void Light_system::move_right_light()
{
    this->light_point[0][0] += this->DX;
}
void Light_system::move_forward_light()
{
    this->light_point[0][2] -= this->DZ;
}
void Light_system::move_back_light()
{
    this->light_point[0][2] += this->DZ;
}




void Light_system::rotate_y_positive_plane(size_t choice)
{
    rotate_y(1, choice);
}
void Light_system::rotate_y_negative_plane(size_t choice)
{
    rotate_y(-1, choice);
}
void Light_system::rotate_x_positive_plane(size_t choice)
{
    rotate_x(1, choice);
}
void Light_system::rotate_x_negative_plane(size_t choice)
{
    rotate_x(-1, choice);
}
void Light_system::rotate_z_positive_plane(size_t choice)
{
    rotate_z(1, choice);
}
void Light_system::rotate_z_negative_plane(size_t choice)
{
    rotate_z(-1, choice);
}

void Light_system::associate_plane_with_polygones(Base_polygone** polygone_array, size_t polugones_pos)
{

    Plane* p;


    

    for (size_t i = 0; i < count_of_planes; i++)
    {
        p = new Plane;

        p->associate(this->planes[i]);

        polygone_array[i + polugones_pos] = p;

    }

    /*Polygone* p;
    for (size_t i = 0; i < polugones_count; i++)
    {
        p = new Polygone;

        p->associate(this->f[rule[i][0]], this->f[rule[i][1]], this->f[rule[i][2]]);

        polygone_array[i + first_elem_pos] = p;


    }
    */
}
void Light_system::associate_light_source_with_polygones(Base_polygone** polygone_array, size_t polugones_pos)
{

    Light_source* l;


    l = new Light_source;
    l->associate(this->light_point);
    polygone_array[polugones_pos] = l;

    /*
    Polygone* p;
    for (size_t i = 0; i < polugones_count; i++)
    {
        p = new Polygone;

        p->associate(this->f[rule[i][0]], this->f[rule[i][1]], this->f[rule[i][2]]);

        polygone_array[i + first_elem_pos] = p;


    }
    */

}





void Light_system::multing(double** lin, double** matrix)
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



Light_system::Light_system(double** coord_light, size_t amount_planes, double*** coord_planes) 
{

    register size_t i;
    register size_t j;
    register size_t k;

    this->DX = 5;
    this->DY = 5;
    this->DZ = 5;

    this->ANGLE = M_PI / 36;

    this->N = 3;
    this->M = 4;

    this->count_of_planes = amount_planes;

    this->light_point = allocate_memory_for_N_M_array<double>(1, this->M);

    create_m_move();

    create_m_rotate_x();
    create_m_rotate_y();
    create_m_rotate_z();

    this->planes = new double**[this->count_of_planes];

    for(k = 0; k< this->count_of_planes; k++)
    {
        this->planes[k] = allocate_memory_for_N_M_array<double>(this->N, this->M);
        for (i = 0; i < this->N; i++)
            for (j = 0; j < this->M; j++)
            {
                this->planes[k][i][j] = coord_planes[k][i][j];
            }
    }

}


Light_system::~Light_system()
{


    if (this->light_point)
    {
        free_memory_for_N_M_array<double>(this->light_point, 1, this->M);
    }

     for (size_t k = 0; k < this->count_of_planes; k++)
     {

         if (this->planes[k])
         {
             free_memory_for_N_M_array<double>(this->planes[k], this->N, this->M);
         }
     }

     if (this->planes)
     {
         delete[] this->planes;
     }

     if (this->m_move)
     {
         free_memory_for_N_M_array<double>(this->m_move, this->M, this->M);
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

}



