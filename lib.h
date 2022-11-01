#pragma once
#include <iostream>

#include <SDL.h>



typedef struct color
{
    uint32_t r : 8;
    uint32_t g : 8;
    uint32_t b : 8;
    uint32_t a : 8;
};

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







#include "polygone.h"

#include "figure.h"

#include "screen.h"