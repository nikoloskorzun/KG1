#pragma once

#include "light_system.h"



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


void Light_system::shadows_create(size_t amount_polygones, Polygone** polygones, Shadow_polygone** shadow_polygones)
{
    //Здесь нужно вызвать функцию которая "создает" теневой полигон для каждого полигона

    size_t iter = 0;

    size_t count_of_vertex;

    double** vertexes = allocate_memory_for_N_M_array<double>(5, 3);;

    for (size_t i = 0; i < count_of_planes; i++)
    {
        for (size_t j = 0; j < amount_polygones; j++)
        {
            count_of_vertex = create_shadow(i, polygones[j], vertexes);

            //cout << vertexes[0][0] << endl;

            shadow_polygones[iter]->set_vertexes(count_of_vertex, vertexes);
            iter++;

        }


    }

    free_memory_for_N_M_array<double>(vertexes, 5, 3);

}



size_t Light_system::create_shadow(size_t number_of_plane, Polygone* polygone, double** vertexes)
{



    point L = { light_point[0][0], light_point[0][1], light_point[0][2] };

    point P1 = { polygone->get_vertex1()[0], polygone->get_vertex1()[1], polygone->get_vertex1()[2] };
    point P2 = { polygone->get_vertex2()[0], polygone->get_vertex2()[1], polygone->get_vertex2()[2] };
    point P3 = { polygone->get_vertex3()[0], polygone->get_vertex3()[1], polygone->get_vertex3()[2] };





    /*
    
    {
1. Идеальный
    L---Ti---P или P---Ti---L
    Пересечение этой прямой с P - искомая точка Ki
2. Источник света между плоскостью и точкой полигона
    Ti---L---P или P---L---Ti
    Тень не создается для этой точки.
3. Плоскость между источником света и точкой полигона
    L---P---Ti или T---P---L
    Тень не создается для этой точки.
4. Плоскость параллельна прямой между источником света и точкой полигона
    L---Ti не пересекает P}

    
    */
    


    line line_L_P1 = point_point2line(L, P1);

    line line_L_P2 = point_point2line(L, P2);
    
    line line_L_P3 = point_point2line(L, P3);



    plane plane_ = plane_with_3_points(point{ planes[number_of_plane][0][0],planes[number_of_plane][0][1],planes[number_of_plane][0][2]}, point{ planes[number_of_plane][1][0],planes[number_of_plane][1][1],planes[number_of_plane][1][2] }, point{ planes[number_of_plane][2][0],planes[number_of_plane][2][1],planes[number_of_plane][2][2] });
    

    point p1 = intersection_line_plane(line_L_P1, plane_);
    point p2 = intersection_line_plane(line_L_P2, plane_);
    point p3 = intersection_line_plane(line_L_P3, plane_);

    //cout << line_L_P1.p.x << " " << line_L_P1.s.x << endl;
    //cout << line_L_P1.p.y << " " << line_L_P1.s.y << endl;
    //cout << line_L_P1.p.z << " " << line_L_P1.s.z << endl;

#ifdef DEBUG



    cout << "PLANE: " << plane_.A << " " << plane_.B << " " << plane_.C << " " << plane_.D << endl;

    cout << "point pol1: " << P1.x << " " << P1.y << " " << P1.z << " " << endl;
    cout << "point pol2: " << P2.x << " " << P2.y << " " << P2.z << " " << endl;
    cout << "point pol3: " << P3.x << " " << P3.y << " " << P3.z << " " << endl;
    cout << "point light: " << L.x << " " << L.y << " " << L.z << " " << endl;
    
    cout << "Line1: (" << line_L_P1.p.x << "; " << line_L_P1.p.y<<"; " << line_L_P1.p.z << ")   (" << line_L_P1.s.x << "; " << line_L_P1.s.y << "; " << line_L_P1.s.z << ")" << endl;
    cout << "Line2: (" << line_L_P2.p.x << "; " << line_L_P2.p.y << "; " << line_L_P2.p.z << ")   (" << line_L_P2.s.x << "; " << line_L_P2.s.y << "; " << line_L_P2.s.z << ")" << endl;
    cout << "Line3: (" << line_L_P3.p.x << "; " << line_L_P3.p.y << "; " << line_L_P3.p.z << ")   (" << line_L_P3.s.x << "; " << line_L_P3.s.y << "; " << line_L_P3.s.z << ")" << endl;

    cout << "point intersect: " << p1.x << " " << p1.y << " " << p1.z << " " << endl;
    cout << "point intersect: " << p2.x << " " << p2.y << " " << p2.z << " " << endl;
    cout << "point intersect: " << p3.x << " " << p3.y << " " << p3.z << " " << endl<<endl;
#endif // DEBUG
    vertexes[0][0] = p1.x;
    vertexes[0][1] = p1.y;
    vertexes[0][2] = p1.z;

    vertexes[1][0] = p2.x;
    vertexes[1][1] = p2.y;
    vertexes[1][2] = p2.z;

    vertexes[2][0] = p3.x;
    vertexes[2][1] = p3.y;
    vertexes[2][2] = p3.z;

    //int type_vertex_1;

   //#TODO
    //

    //

    //



    return 3;

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
    
    for (i = 0; i < 4; i++)
        this->light_point[0][i] = coord_light[0][i];




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



