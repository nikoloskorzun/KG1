#pragma once



#include <iostream>

#include <SDL.h>




using namespace std;





class Figure {


    typedef struct color
    {
        uint32_t r : 8;
        uint32_t g : 8;
        uint32_t b : 8;
        uint32_t a : 8;
    };



public:
    class Polygone
    {
    public:

        double z;


        Polygone(const Polygone& plygone_copy)
        {
            cout << "copy ERROR\n";

        }

        Polygone()
        {
            this->N = 3;
            this->z = NULL;
            this->f = new double* [this->N];

            this->c.r = rand() % 255;
            this->c.g = rand() % 255;
            this->c.b = rand() % 255;
            this->c.a = 255;


        }


        Polygone& operator=(const Polygone& right) {
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

        ~Polygone()
        {


            delete[] this->f;

        }

        void set_z()
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
                
               

                
                

            cout << az << " " << bz << " " << cz << "\n" << this->z <<"\n";





            //
            //this->z = (f[0][2] + f[1][2] + f[2][2]) / 3;


        }

        void associate(double* d1, double* d2, double* d3)
        {
            f[0] = d1;
            f[1] = d2;
            f[2] = d3;


        }





        void draw(SDL_Renderer* ren)
        {

            /*
            double a = f[0][1] * (f[1][2] - f[2][2]) + f[1][1] * (f[2][2] - f[0][2]) + f[2][1] * (f[0][2] - f[1][2]);
            double b = f[0][0] * (f[2][2] - f[1][2]) + f[1][0] * (f[0][2] - f[2][2]) + f[2][0] * (f[1][2] - f[0][2]);
            //double c = f[0][0] * (f[1][1] - f[2][1]) + f[1][0] * (f[2][1] - f[0][1]) + f[2][0] * (f[0][1] - f[1][1]);

            double x1 = (f[0][0] + f[1][0] + f[2][0]) / 3;
            double y1 = (f[0][1] + f[1][1] + f[2][1]) / 3;
            double x2 = x1 + a;
            double y2 = y1 + b;
            Нормаль

           SDL_RenderDrawLine(ren, x1, y1, x2, y2);
           */


            SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, c.a);

           //





            if (f[0][0] > f[1][0])
                swap_d(&f[0], &f[1]);
            if (f[0][0] > f[2][0])
                swap_d(&f[0], &f[2]);
            if (f[1][0] > f[2][0])
                swap_d(&f[1], &f[2]);


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

            if (f[0][1] > f[1][1])
                swap_d(&f[0], &f[1]);
            if (f[0][1] > f[2][1])
                swap_d(&f[0], &f[2]);
            if (f[1][1] > f[2][1])
                swap_d(&f[1], &f[2]);
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

    private:
        double** f;
        uint32_t N;

        color c;



        void swap_d(double** a, double** b)
        {
            double* t = *a;
            *a = *b;
            *b = t;
        }


    };








public:


    Figure()
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


    void painter_algoritm(SDL_Renderer * ren)
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

    void set(size_t n, double** coords, size_t** info, size_t len)
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

    Figure(size_t n, double** coords, size_t** info, size_t len)
    {
        this->set(n, coords, info, len);
    }
    ~Figure()
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


        if(this->Polygones)
            delete[] this->Polygones;

    }




    void move_up()
    {
        
        m_move[3][0] = 0; // 
        m_move[3][1] = -this->DY; // 
        m_move[3][2] = 0; //


        multing(this->f, m_move);
    }
    void move_down()
    {
        m_move[3][0] = 0; // 
        m_move[3][1] = this->DY; // 
        m_move[3][2] = 0; //


        multing(this->f, m_move);
    }
    void move_left()
    {
        m_move[3][0] = -this->DX; // 
        m_move[3][1] = 0; // 
        m_move[3][2] = 0; //


        multing(this->f, m_move);
    }
    void move_right()
    {
        m_move[3][0] = this->DX; // 
        m_move[3][1] = 0; // 
        m_move[3][2] = 0; //


        multing(this->f, m_move);
    }



    void rotate_y_positive()
    {
        rotate_y(1);
    }

    void rotate_y_negative()
    {
        rotate_y(-1);
    }

    void rotate_x_positive()
    {
        rotate_x(1);
    }

    void rotate_x_negative()
    {
        rotate_x(-1);
    }

    void rotate_z_positive()
    {
        rotate_z(1);
    }

    void rotate_z_negative()
    {
        rotate_z(-1);
    }

    void scale_up()
    {
        scaling(0);
    }    
    
    void scale_down()
    {
        scaling(-1);

    }




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

    void draw(SDL_Renderer* ren)
    {

        for (register size_t i = 0; i < this->Polygone_count; i++)
            Polygones[i].draw(ren);


       

    }


  





    inline void create_m_move()
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


    inline void create_m_scale()
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



    inline void create_m_rotate_x()
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
    inline void create_m_rotate_y()
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
    inline void create_m_rotate_z()
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



    //функция поворота вокруг оси Y
    inline void rotate_y(double k)
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

        this->m_rotate_y[3][0] = xc * (1 - cos(this->ANGLE)) - zc * sin(k*this->ANGLE);
        
        this->m_rotate_y[3][2] = zc * (1 - cos(this->ANGLE)) + xc * sin(k*this->ANGLE);
        

        multing(this->f, this->m_rotate_y);

    }



    //функция поворота вокруг оси X
    inline void rotate_x(double k)
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

        this->m_rotate_x[3][1] = yc * (1 - cos(this->ANGLE)) + zc * sin(k*this->ANGLE);
        this->m_rotate_x[3][2] = zc * (1 - cos(this->ANGLE)) - yc * sin(k*this->ANGLE);

        multing(this->f, this->m_rotate_x);


    }

    
    //функция поворота вокруг оси Z
    inline void rotate_z(double k)
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

    inline void scaling(double k)
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


    
    void multing(double **lin, double **matrix)
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


    template<typename T>
    inline T** allocate_memory_for_N_M_array(size_t n, size_t m)
    {
        register size_t i;
        T** temp = new T * [n];
        for (i = 0; i < n; i++)
            temp[i] = new T[m];
        return temp;
    }

    template<typename T>
    inline void free_memory_for_N_M_array(T** arr, size_t n, size_t m)
    {

        register size_t i;
        for (i = 0; i < n; i++)
            delete[] arr[i];
        delete[] arr;
    }


};
