#pragma once
#include <iostream>

#include <SDL.h>
#include "figure.cpp"










using namespace std;
class Screen
{



public:


    Screen(uint32_t width, uint32_t height) {

        cout << "START!\n";


        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
            return;
        }

        if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE, &win, &ren)) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
            return;
        }

        this->width = width;
        this->height = height;


    }




    void add_figures()
    {

        this->figures = new Figure[2];

        size_t** i_ = allocate_memory_for_N_M_array<size_t>(12, 3);


        i_[0][0] = 0;
        i_[0][1] = 1;
        i_[0][2] = 2;

        i_[1][0] = 0;
        i_[1][1] = 1;
        i_[1][2] = 3;

        i_[2][0] = 0;
        i_[2][1] = 1;
        i_[2][2] = 4;

        i_[3][0] = 0;
        i_[3][1] = 1;
        i_[3][2] = 5;

        //
        i_[4][0] = 3;
        i_[4][1] = 7;
        i_[4][2] = 1;

        i_[5][0] = 3;
        i_[5][1] = 7;
        i_[5][2] = 2;
        
        i_[6][0] = 3;
        i_[6][1] = 7;
        i_[6][2] = 5;

        i_[7][0] = 3;
        i_[7][1] = 7;
        i_[7][2] = 6;

        //
        i_[8][0] = 4;
        i_[8][1] = 6;
        i_[8][2] = 0;

        i_[9][0] = 4;
        i_[9][1] = 6;
        i_[9][2] = 2;

        i_[10][0] = 4;
        i_[10][1] = 6;
        i_[10][2] = 5;

        i_[11][0] = 4;
        i_[11][1] = 6;
        i_[11][2] = 7;

        double** AB = allocate_memory_for_N_M_array<double>(8, 4);

        AB[0][0] = 0;
        AB[0][1] = 0;
        AB[0][2] = 0;
        AB[0][3] = 1;

        AB[1][0] = 100;
        AB[1][1] = 0;
        AB[1][2] = 0;
        AB[1][3] = 1;

        AB[2][0] = 0;
        AB[2][1] = 0;
        AB[2][2] = 100;
        AB[2][3] = 1;

        AB[3][0] = 100;
        AB[3][1] = 0;
        AB[3][2] = 100;
        AB[3][3] = 1;

        AB[4][0] = 0;
        AB[4][1] = 100;
        AB[4][2] = 0;
        AB[4][3] = 1;

        AB[5][0] = 100;
        AB[5][1] = 100;
        AB[5][2] = 0;
        AB[5][3] = 1;

        AB[6][0] = 0;
        AB[6][1] = 100;
        AB[6][2] = 100;
        AB[6][3] = 1;

        AB[7][0] = 100;
        AB[7][1] = 100;
        AB[7][2] = 100;
        AB[7][3] = 1;



        this->figures[0].set(8, AB, i_, 12);
        
        
        free_memory_for_N_M_array<size_t>(i_, 12, 3);
        free_memory_for_N_M_array<double>(AB, 8, 4);


        i_ = allocate_memory_for_N_M_array<size_t>(4, 3);


        i_[0][0] = 0;
        i_[0][1] = 1;
        i_[0][2] = 2;

        i_[1][0] = 0;
        i_[1][1] = 1;
        i_[1][2] = 3;

        i_[2][0] = 0;
        i_[2][1] = 3;
        i_[2][2] = 2;

        i_[3][0] = 1;
        i_[3][1] = 2;
        i_[3][2] = 3;

         AB = allocate_memory_for_N_M_array<double>(4, 4);

        AB[0][0] = 100;
        AB[0][1] = 100;
        AB[0][2] = 200;
        AB[0][3] = 1;

        AB[1][0] = 0;
        AB[1][1] = 0;
        AB[1][2] = 0;
        AB[1][3] = 1;

        AB[2][0] = 0;
        AB[2][1] = 200;
        AB[2][2] = 0;
        AB[2][3] = 1;

        AB[3][0] = 200;
        AB[3][1] = 200;
        AB[3][2] = 0;
        AB[3][3] = 1;



        this->figures[1].set(4, AB, i_, 4);


        free_memory_for_N_M_array<size_t>(i_, 4, 3);
        free_memory_for_N_M_array<double>(AB, 4, 4);

    }

    int cycle()
    {
        SDL_Event event;



        size_t figure_choice = 0;
        int exit = 1;
        while (exit == 1)
        {

            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    exit = 0;
                }


                if ((event.type == SDL_KEYDOWN))
                {


                    



                    switch (event.key.keysym.sym)
                    {
                    case SDLK_1:
                        figure_choice = 0;
                        
                        break;
                    case SDLK_2:
                        figure_choice = 1;
                        
                        break;
                    case SDLK_w:
                        this->figures[figure_choice].move_up();
                        //figures->move_up();
                        break;
                    case SDLK_a:

                        //figures->move_left();
                        this->figures[figure_choice].move_left();
                        break;
                    case SDLK_s:
                        //figures->move_down();
                        this->figures[figure_choice].move_down();
                        break;
                    case SDLK_d:
                        this->figures[figure_choice].move_right();
                        //figures->move_right();
                        break;


                    case SDLK_UP:
                        this->figures[figure_choice].rotate_x_positive();
                        break;
                    case SDLK_DOWN:
                        this->figures[figure_choice].rotate_x_negative();
                        break;
                    case SDLK_RIGHT:
                        this->figures[figure_choice].rotate_y_positive();
                        break;
                    case SDLK_LEFT:
                        this->figures[figure_choice].rotate_y_negative();
                        break;
                    case SDLK_z:
                        this->figures[figure_choice].rotate_z_positive();
                        break;
                    case SDLK_x:
                        this->figures[figure_choice].rotate_z_negative();
                        break;
                    case SDLK_KP_PLUS:
                        this->figures[figure_choice].scale_up();
                        break;
                    case SDLK_KP_MINUS:
                        this->figures[figure_choice].scale_down();
                        break;






                    }

                    //draw
                    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);
                    SDL_RenderClear(ren);

                    this->figures[0].painter_algoritm(ren);
                    this->figures[1].painter_algoritm(ren);

                    SDL_RenderPresent(ren);



                }




            }



        }
        return 0;

    }



    ~Screen() {

        cout << "THE END!\n";
        if (ren)
        {
            SDL_DestroyRenderer(ren);
        }
        if (win)
        {
            SDL_DestroyWindow(win);
        }

        SDL_Quit();
    }







private:



    SDL_Window* win;

    SDL_Renderer* ren = NULL;

    uint32_t width = NULL;

    uint32_t height = NULL;






    Figure* figures = NULL;




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

