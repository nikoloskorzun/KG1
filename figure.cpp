#include "lib.h"

using namespace std;


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

    this->Polygone_count = NULL;

    this->Polygones = NULL;

}

void Figure::painter_algoritm(SDL_Renderer* ren)
{

    register size_t i;
    register size_t j;
    register size_t id;
    for (i = 0; i < Polygone_count; i++)
        Polygones[i].set_z();


    Polygone b;
    j = Polygone_count - 1;
    while (j > 0)
    {
        id = 0;
        for (i = 1; i <= j; i++)
            if (Polygones[i].z > Polygones[id].z)
                id = i;

        b = Polygones[id];
        Polygones[id] = Polygones[j];
        Polygones[j] = b;


        j--;
    }







    draw(ren);

}

void Figure::set(size_t n, double** coords, size_t** info, size_t len)
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

    for (i = 0; i < this->N; i++)
        for (j = 0; j < this->M; j++)
        {
            this->f[i][j] = coords[i][j];
        }


    this->Polygone_count = len;



    this->Polygones = new Polygone[this->Polygone_count];


    for (i = 0; i < this->Polygone_count; i++)
    {


        this->Polygones[i].associate(this->f[info[i][0]], this->f[info[i][1]], this->f[info[i][2]]);



    }


}


Figure::Figure(size_t n, double** coords, size_t** info, size_t len)
{
    this->set(n, coords, info, len);
}

Figure::~Figure()
{


    if (this->f)
    {
        free_memory_for_N_M_array<double>(this->f, this->N, this->M);
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
        free_memory_for_N_M_array<double>(this->m_rotate_x, this->M, this->M);
    }

    if (this->m_rotate_z)
    {
        free_memory_for_N_M_array<double>(this->m_rotate_x, this->M, this->M);
    }


    if (this->Polygones)
        delete[] this->Polygones;

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


void Figure::draw(SDL_Renderer* ren)
{

    for (register size_t i = 0; i < this->Polygone_count; i++)
        Polygones[i].draw(ren);

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







//функция поворота вокруг оси X
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

//функция поворота вокруг оси Y
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

//функция поворота вокруг оси Z
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



    multing(this->f, this->m_scale); //умножение матрицы отрезка на матрицу масштабирования
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



