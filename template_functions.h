#pragma once
#include <iostream>


typedef struct Color
{
    uint32_t r : 8;
    uint32_t g : 8;
    uint32_t b : 8;
    uint32_t a : 8;
};


template<typename T>
inline T** allocate_memory_for_N_M_array(size_t n, size_t m);

template<typename T>
inline void free_memory_for_N_M_array(T** arr, size_t n, size_t m);