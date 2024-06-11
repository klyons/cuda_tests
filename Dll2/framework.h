#ifndef YOUR_DLL_HEADER_H
#define YOUR_DLL_HEADER_H
#include <utility>

extern "C" {
    __declspec(dllexport) void process_arrays(int nLen, double* result_array, unsigned short** ushort_array, double** double_array);
    //__declspec(dllexport) void display(double* arr, int size);
}