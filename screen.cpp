#pragma once
#include <iostream>
#include <SDL.h>


#include "screen.h"
#include "figure.h"
#include "polygone.h"

#include "template_functions.cpp"


using namespace std;

static int double_compare(const void* p1, const void* p2)
{
    double a = (*((Base_polygone**)(p1)))->z;
    double b = (*((Base_polygone**)(p2)))->z;

    //cout << a<<" " << b << endl;

        
    if (a < b) return -1;
    if (a == b) return 0;
    return 1;
    
}


Screen::Screen(uint32_t width, uint32_t height) {

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



void Screen::add_figures()//это функция говна, ее можно переписать и сделать инициализацию фигур нормальной, но зачем?
{
    this->polygones = new Base_polygone * [(12 + 8) * 2 + 1 + 1];
    this->polygone_count = (12 + 8) * 2 + 1 + 1;


    polygones_for_shadow = new Polygone * [12 + 8];
    polygones_projection = new Base_polygone * [12 + 8];
    shadow_polygones_for_shadow = new Shadow_polygone * [12 + 8];


    size_t i = 0;


    this->figures = new Figure[2];

    size_t** i_ = allocate_memory_for_N_M_array<size_t>(12, 3);


    i_[0][0] = 0;
    i_[0][1] = 1;
    i_[0][2] = 3;

    i_[1][0] = 0;
    i_[1][1] = 2;
    i_[1][2] = 3;

    i_[2][0] = 4;
    i_[2][1] = 5;
    i_[2][2] = 7;

    i_[3][0] = 4;
    i_[3][1] = 6;
    i_[3][2] = 7;

    //
    i_[4][0] = 0;
    i_[4][1] = 1;
    i_[4][2] = 4;

    i_[5][0] = 1;
    i_[5][1] = 4;
    i_[5][2] = 5;

    i_[6][0] = 2;
    i_[6][1] = 3;
    i_[6][2] = 6;

    i_[7][0] = 3;
    i_[7][1] = 6;
    i_[7][2] = 7;

    //
    i_[8][0] = 0;
    i_[8][1] = 2;
    i_[8][2] = 6;

    i_[9][0] = 0;
    i_[9][1] = 4;
    i_[9][2] = 6;

    i_[10][0] = 1;
    i_[10][1] = 3;
    i_[10][2] = 7;

    i_[11][0] = 1;
    i_[11][1] = 5;
    i_[11][2] = 7;

    double** AB = allocate_memory_for_N_M_array<double>(8, 4);

    AB[0][0] = 0;
    AB[0][1] = 0;
    AB[0][2] = 0;
    AB[0][3] = 1;

    AB[1][0] = 0;
    AB[1][1] = 100;
    AB[1][2] = 0;
    AB[1][3] = 1;

    AB[2][0] = 100;
    AB[2][1] = 0;
    AB[2][2] = 0;
    AB[2][3] = 1;

    AB[3][0] = 100;
    AB[3][1] = 100;
    AB[3][2] = 0;
    AB[3][3] = 1;

    AB[4][0] = 0;
    AB[4][1] = 0;
    AB[4][2] = 200;
    AB[4][3] = 1;

    AB[5][0] = 0;
    AB[5][1] = 100;
    AB[5][2] = 200;
    AB[5][3] = 1;

    AB[6][0] = 100;
    AB[6][1] = 0;
    AB[6][2] = 200;
    AB[6][3] = 1;

    AB[7][0] = 100;
    AB[7][1] = 100;
    AB[7][2] = 200;
    AB[7][3] = 1;



    this->figures[0].set(8, AB);



    this->figures[0].associate_figure_with_polygones(this->polygones, i_, 12);
    this->figures[0].associate_figure_proj_with_polygones(this->polygones_projection, i_, 12);


    free_memory_for_N_M_array<size_t>(i_, 12, 3);
    free_memory_for_N_M_array<double>(AB, 8, 4);


    i_ = allocate_memory_for_N_M_array<size_t>(8, 3);


    i_[0][0] = 0;
    i_[0][1] = 1;
    i_[0][2] = 2;

    i_[1][0] = 3;
    i_[1][1] = 4;
    i_[1][2] = 5;

    i_[2][0] = 0;
    i_[2][1] = 1;
    i_[2][2] = 3;

    i_[3][0] = 1;
    i_[3][1] = 3;
    i_[3][2] = 4;


    i_[4][0] = 1;
    i_[4][1] = 2;
    i_[4][2] = 5;

    i_[5][0] = 1;
    i_[5][1] = 4;
    i_[5][2] = 5;

    i_[6][0] = 0;
    i_[6][1] = 2;
    i_[6][2] = 3;

    i_[7][0] = 2;
    i_[7][1] = 3;
    i_[7][2] = 5;


    AB = allocate_memory_for_N_M_array<double>(6, 4);

    AB[0][0] = 0;
    AB[0][1] = 0;
    AB[0][2] = 0;
    AB[0][3] = 1;

    AB[1][0] = 100;
    AB[1][1] = 50;
    AB[1][2] = 0;
    AB[1][3] = 1;

    AB[2][0] = 0;
    AB[2][1] = 100;
    AB[2][2] = 0;
    AB[2][3] = 1;

    AB[3][0] = 0;
    AB[3][1] = 0;
    AB[3][2] = 200;
    AB[3][3] = 1;

    AB[4][0] = 100;
    AB[4][1] = 50;
    AB[4][2] = 200;
    AB[4][3] = 1;

    AB[5][0] = 0;
    AB[5][1] = 100;
    AB[5][2] = 200;
    AB[5][3] = 1;



    this->figures[1].set(6, AB);
    this->figures[1].associate_figure_with_polygones(this->polygones, i_, 8, 12);
    this->figures[1].associate_figure_proj_with_polygones(this->polygones_projection, i_, 8, 12);

    for (i = 0; i < 12 + 8; i++)
    {
        polygones_for_shadow[i] = (Polygone*)this->polygones[i];

    }



    free_memory_for_N_M_array<size_t>(i_, 8, 3);
    free_memory_for_N_M_array<double>(AB, 6, 4);


    double** l = allocate_memory_for_N_M_array<double>(1, 4);
    l[0][0] = 200;
    l[0][1] = 200;
    l[0][2] = 5000;
    l[0][3] = 1;

    double*** p = new double** [1];


    p[0] = allocate_memory_for_N_M_array<double>(3, 4);

    p[0][0][0] = 0;
    p[0][0][1] = 0;
    p[0][0][2] = -1000;
    p[0][0][3] = 1;

    p[0][1][0] = 100;
    p[0][1][1] = 0;
    p[0][1][2] = -1000;
    p[0][1][3] = 1;

    p[0][2][0] = 0;
    p[0][2][1] = 100;
    p[0][2][2] = -1000;
    p[0][2][3] = 1;

    this->light_system = new Light_system(l, 1, p);


    this->light_system->associate_plane_with_polygones(this->polygones, 12 + 8);

    this->light_system->associate_light_source_with_polygones(this->polygones, 12 + 8 + 1);



    Shadow_polygone* sp_t;
    for (i = 0; i < 12 + 8; i++)
    {
    sp_t = new Shadow_polygone;
    polygones[12 + 8 + 1 + 1 + i] = sp_t;

    shadow_polygones_for_shadow[i] = sp_t;
    }










    free_memory_for_N_M_array<double>(l, 1, 4);


    free_memory_for_N_M_array<double>(p[0], 3, 4);//lol

    delete[] p;
    




}



int Screen::cycle()
{
    cout << "Control:\n";
    cout << "\n\tMove:\n";
    cout << "\t[w] - y--\n";
    cout << "\t[a] - x--\n";
    cout << "\t[s] - y++\n";
    cout << "\t[d] - x++\n";
    cout << "\t[q] - z--\n";
    cout << "\t[e] - z++\n";

    cout << "\n\tRotate:\n";
    cout << "\t[^] - y- rotate\n";
    cout << "\t[v] - y+ rotate\n";
    cout << "\t[>] - x- rotate\n";
    cout << "\t[<] - x+ rotate\n";
    cout << "\t[z] - z- rotate\n";
    cout << "\t[x] - z+ rotate\n";

    cout << "\n\tScale:\n";
    cout << "\t[+] - increase size\n";
    cout << "\t[-] - decrease size\n";

    cout << "\n\tChoice:\n";
    cout << "\t[l] - on/off light control\n";
    cout << "\t[p] - if light control ON plane control ON/OFF\n";

    cout << "\t[0] - projection on/off\n";

    cout << "\n\tlight control OFF\n";
    cout << "\t[1] - choice figure 1\n";
    cout << "\t[2] - choice figure 2\n";

    cout << "\n\tlight control ON\n";
    cout << "\t[1] - choice plane 1\n";
    cout << "\t[2] - choice plane 2\n";




 

    SDL_Event event;



    size_t figure_choice = 0;
    size_t plane_choice = 0;

    int plane_flag = 0;

    int exit = 1;
    int light_exit = 1;

    int proj_flag = 0;

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

                case SDLK_l:
                    if (proj_flag)
                        break;
                    //управление "светом"
                    light_exit = 1;
                    while(light_exit)
                    {
                        while (SDL_PollEvent(&event))
                        {
                            if (event.type == SDL_QUIT)
                            {
                                exit = 0;
                                light_exit = 0;
                            }

                            if ((event.type == SDL_KEYDOWN))
                            {
                                switch (event.key.keysym.sym)
                                {
                                case SDLK_l:
                                    light_exit = 0;
                                    break;
                                case SDLK_p:
                                    if (plane_flag)
                                        plane_flag = 0;
                                    else
                                        plane_flag = 1;
                                    break;



                                case SDLK_w:
                                    if (plane_flag)
                                        this->light_system->move_up_plane(plane_choice);
                                    else
                                        this->light_system->move_up_light();
                                    break;
                                case SDLK_s:
                                    if (plane_flag)
                                        this->light_system->move_down_plane(plane_choice);
                                    else
                                        this->light_system->move_down_light();
                                    break;

                                case SDLK_a:
                                    if (plane_flag)
                                        this->light_system->move_left_plane(plane_choice);
                                    else
                                        this->light_system->move_left_light();
                                    break;
                                case SDLK_d:
                                    if (plane_flag)
                                        this->light_system->move_right_plane(plane_choice);
                                    else
                                        this->light_system->move_right_light();
                                    break;
                                case SDLK_q:
                                    if (plane_flag)
                                        this->light_system->move_forward_plane(plane_choice);
                                    else
                                        this->light_system->move_forward_light();
                                    break;
                                case SDLK_e:
                                    if (plane_flag)
                                        this->light_system->move_back_plane(plane_choice);
                                    else
                                        this->light_system->move_back_light();
                                    break;


                                case SDLK_UP:
                                    if (plane_flag)
                                        this->light_system->rotate_x_positive_plane(plane_choice);
                                    break;
                                case SDLK_DOWN:
                                    if (plane_flag)
                                        this->light_system->rotate_x_negative_plane(plane_choice);
                                    break;
                                case SDLK_RIGHT:
                                    if (plane_flag)
                                        this->light_system->rotate_y_positive_plane(plane_choice);
                                    break;
                                case SDLK_LEFT:
                                    this->light_system->rotate_y_negative_plane(plane_choice);
                                    break;
                                case SDLK_z:
                                    if (plane_flag)
                                        this->light_system->rotate_z_positive_plane(plane_choice);
                                    break;
                                case SDLK_x:
                                        this->light_system->rotate_z_negative_plane(plane_choice);
                                    break;


                                case SDLK_1:
                                    if (plane_flag)
                                        plane_choice = 0;

                                    break;


                                case SDLK_2:
                                    if (plane_flag)
                                        plane_choice = 0;

                                    break;



                                }
                            
                                SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);
                                SDL_RenderClear(ren);


                                draw_poligones(ren);

                                SDL_RenderPresent(ren);

                            
                            }
                        }
                    
                    }
                    break;
                
                case SDLK_0:
                    if(proj_flag)
                        proj_flag = 0;
                    else
                        proj_flag = 1;
                    break;

                case SDLK_1:
                    figure_choice = 0;

                    break;
                case SDLK_2:
                    figure_choice = 1;

                    break;
                case SDLK_w:
                    this->figures[figure_choice].move_up();
                    
                    break;
                case SDLK_a:

                    
                    this->figures[figure_choice].move_left();
                    break;
                case SDLK_s:
                    
                    this->figures[figure_choice].move_down();
                    break;
                case SDLK_d:
                    this->figures[figure_choice].move_right();
                    
                    break;
                case SDLK_q:
                    
                    this->figures[figure_choice].move_forward();
                    break;
                case SDLK_e:
                    this->figures[figure_choice].move_back();
                    
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
                if (proj_flag)
                {

                    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);
                    SDL_RenderClear(ren);



                    figures[0].create_projection();
                    figures[1].create_projection();
                    for (register size_t i = 0; i < 12 + 8; i++)
                        polygones_projection[i]->draw(ren);

                    SDL_RenderPresent(ren);

                }
                else
                {
                    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);
                    SDL_RenderClear(ren);

                    draw_poligones(ren);


                    SDL_RenderPresent(ren);


                }





            }




        }



    }
    return 0;

}



Screen::~Screen() {

    cout << "THE END!\n";
    if (ren)
    {
        SDL_DestroyRenderer(ren);
    }
    if (win)
    {
        SDL_DestroyWindow(win);
    }

    if (polygones)
    {
        for (size_t i = 0; i < polygone_count; i++)
            delete polygones[i];
        delete[] polygones;

    }
    if (polygones_projection)
    {
        for (size_t i = 0; i < 12 + 8; i++)
            delete polygones_projection[i];
        delete[] polygones_projection;

    }



    if (polygones_for_shadow)
        delete[] polygones_for_shadow;
    if (shadow_polygones_for_shadow)
        delete[] shadow_polygones_for_shadow; 
    if (figures)
        delete[] figures;
    
    if (light_system)
        delete light_system;

    SDL_Quit();
}


void Screen::draw_poligones(SDL_Renderer* ren)
{
    
    light_system->shadows_create(12 + 8, polygones_for_shadow, shadow_polygones_for_shadow);//построение теней




    painter_algorithm(); //сортировка по z - так "работает" алгоритм художника

    
    for (register size_t i = 0; i < polygone_count; i++)
        polygones[i]->draw(ren);

}

void Screen::painter_algorithm()
{


    register size_t i;

    for (i = 0; i < polygone_count; i++)
    { 
        polygones[i]->set_z();
       // cout << polygones[i]->z<<endl;
    }


    qsort(polygones, polygone_count, sizeof(Base_polygone*), double_compare);



}