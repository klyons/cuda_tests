// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <cstdio>
#include <utility>

extern "C" {
    __declspec(dllexport) void process_arrays(int nLen, unsigned short** ushort_array, double** double_array) {
        // Allocate memory for the arrays
        *ushort_array = new unsigned short[nLen];
        *double_array = new double[nLen];

        // Fill the arrays and multiply each element by 2.25
        for (int i = 0; i < nLen; i++) {
            (*ushort_array)[i] = (unsigned short)(i * 2.25);
            (*double_array)[i] = i * 2.25;
        }
    }
}
