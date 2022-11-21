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
        return line{ p1, vector_{p2.x - p1.x, p2.y - p1.y, p2.z - p1.z} };
    }

    line paral_line_through_point(line l, point p)
    {
        //прямая параллельная данной через точку
        return line{ p, l.s };
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

