#pragma once
#include <iostream>


#include "base_polygone.h"
#include "shadow_polygone.h"
#include "polygone.h"

#include "plane.h"
#include "light_source.h"

#include "template_functions.h"



using namespace std;


// 

class Light_system
{
private:
    // Математическая оснастка


    typedef struct point
    {
        double x;
        double y;
        double z;
    };

    typedef struct vector_
    {
        double x;
        double y;
        double z;
    };


    typedef struct line
    {
        point p;
        vector_ s;
    };

    typedef struct plane
    {
        double A;
        double B;
        double C;
        double D;
    };


    line point_point2line(point p1, point p2)
    {
        //прямая по 2 точкам
        return line{ p2, vector_{p1.x - p2.x, p1.y - p2.y, p1.z - p2.z} };
    }

    line paral_line_through_point(line l, point p)
    {
        //прямая параллельная данной через точку
        return line{ p, l.s };
    }

    point intersection_line_plane(line l, plane p)
    {


        if ((p.A * (l.s.x) + p.B * (l.s.y) + p.C * (l.s.z)) == 0)
        { 
            cout << "ERR div by zero!\n\n";
            return point{ 0,0,0 };
        }
        double t = (-(p.A * (l.p.x) + p.B * (l.p.y) + p.C * (l.p.z) + p.D))/ (p.A * (l.s.x) + p.B * (l.s.y) + p.C * (l.s.z));



        return point{l.p.x + l.s.x*t, l.p.y + l.s.y * t, l.p.z + l.s.z * t};
        //О***ть вот так можно было, вот это кайф реально
        double** m = allocate_memory_for_N_M_array<double>(3, 3);

        m[0][0] = l.s.y;
        m[0][1] = -l.s.x;
        m[0][2] = 0;

        m[1][0] = 0;
        m[1][1] = l.s.z;
        m[1][2] = -l.s.y;

        m[2][0] = p.A;
        m[2][1] = p.B;
        m[2][2] = p.C;

        double* v = new double[3];

        v[0] = l.s.y * l.p.x - l.s.x * l.p.y;
        v[1] = l.s.z * l.p.y - l.s.y * l.p.z;
        v[2] = -p.D;


        double* ans = fucking_Cramer_LS_solver(m, v, 3);

        point P{ ans[0], ans[1], ans[2] };

        delete[] ans;
        delete[] v;
        free_memory_for_N_M_array<double>(m, 3, 3);

        return P;
    }


    plane plane_with_3_points(point p1, point p2, point p3)
    {
        return plane{ p1.y * (p2.z - p3.z) + p2.y * (p3.z - p1.z) + p3.y * (p1.z - p2.z),
            p1.x * (p3.z - p2.z) + p2.x * (p1.z - p3.z) + p3.x * (p2.z - p1.z),
            p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y),
            -(p1.x * (p2.y * p3.z - p3.y * p2.z) + p2.x * (p3.y * p1.z - p1.y * p3.z) + p3.x * (p1.y * p2.z - p2.y * p1.z)) };



    }
    
    double determinant(double** mat, size_t n)
    {
        if (n == 3)
            return (mat[0][0]*mat[1][1]*mat[2][2] - mat[0][0] * mat[1][2] * mat[2][1] - mat[0][1] * mat[1][0] * mat[2][2] + mat[0][1] * mat[1][2] * mat[2][0] + mat[0][2] * mat[1][0] * mat[2][1] - mat[0][2] * mat[1][1] * mat[2][0]);
            
        cout << "ERROR:DETERMINANT!\n";
        return 0;

    }

    double* fucking_Cramer_LS_solver(double** mat, double* vec, size_t n)
    {

        if (n != 3)
        {
            cout << "Cramer Error\n";
            return NULL;
        }
        double* ans = new double[n];

        double det = determinant(mat, n);

        double** mat_ = allocate_memory_for_N_M_array<double>(n, n);

        mat_[0][0] = vec[0];
        mat_[0][1] = vec[1];
        mat_[0][2] = vec[2];

        mat_[1][0] = mat[1][0];
        mat_[1][1] = mat[1][1];
        mat_[1][2] = mat[1][2];

        mat_[2][0] = mat[2][0];
        mat_[2][1] = mat[2][1];
        mat_[2][2] = mat[2][2];




        double det1 = determinant(mat_, n);
        mat_[0][0] = mat[0][0];
        mat_[0][1] = mat[0][1];
        mat_[0][2] = mat[0][2];

        mat_[1][0] = vec[0];
        mat_[1][1] = vec[1];
        mat_[1][2] = vec[2];
        double det2 = determinant(mat_, n);
        mat_[1][0] = mat[1][0];
        mat_[1][1] = mat[1][1];
        mat_[1][2] = mat[1][2];

        mat_[2][0] = vec[0];
        mat_[2][1] = vec[1];
        mat_[2][2] = vec[2];
        double det3 = determinant(mat_, n);


        if (det == 0)
            det = 0.000001;
        ans[0] = det1 / det;
        ans[1] = det2 / det;
        ans[2] = det3 / det;

        free_memory_for_N_M_array<double>(mat_, n, n);

        return ans;
    }




public:
    Light_system(double **coord_light, size_t amount_planes, double*** coord_planes);

    //Light_system(size_t n, double** coords);

    ~Light_system();

    void move_up_plane(size_t choice);
    void move_down_plane(size_t choice);
    void move_left_plane(size_t choice);
    void move_right_plane(size_t choice);
    void move_forward_plane(size_t choice);
    void move_back_plane(size_t choice);

    void move_up_light();
    void move_down_light();
    void move_left_light();
    void move_right_light();
    void move_forward_light();
    void move_back_light();


    void associate_plane_with_polygones(Base_polygone** polygone_array, size_t polugones_pos);
    void associate_light_source_with_polygones(Base_polygone** polygone_array, size_t polugones_pos);


    void shadows_create(size_t amount_polygones, Polygone** polygones, Shadow_polygone** shadow_polygones);


    
    void rotate_y_positive_plane(size_t choice);
    void rotate_y_negative_plane(size_t choice);
    void rotate_x_positive_plane(size_t choice);
    void rotate_x_negative_plane(size_t choice);
    void rotate_z_positive_plane(size_t choice);
    void rotate_z_negative_plane(size_t choice);
    

private:



    size_t create_shadow(size_t number_of_plane, Polygone * polygone, double** vertexes);


    double** m_move;

    double** m_rotate_x;
    double** m_rotate_y;
    double** m_rotate_z;








    double** light_point;//1*4

    double*** planes;//count_of_planes*3*4

    size_t count_of_planes;

    size_t N;// = 3 always

    size_t M; // = 4 always

    double DX;
    double DY;
    double DZ;

    double ANGLE;


    inline void create_m_move();


    inline void create_m_rotate_x();
    inline void create_m_rotate_y();
    inline void create_m_rotate_z();




    inline void rotate_x(double k, size_t number_of_plane);
    inline void rotate_y(double k, size_t number_of_plane);
    inline void rotate_z(double k, size_t number_of_plane);



    void multing(double** lin, double** matrix);





};

