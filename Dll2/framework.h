#ifndef YOUR_DLL_HEADER_H
#define YOUR_DLL_HEADER_H
#include <utility>

extern "C" {
    __declspec(dllexport) void process_arrays(int nLen, unsigned short** ushort_array, double** double_array);
    __declspec(dllexport) void add_to_arrays(int nLen, double* pArray, double** pRefResult);
    //__declspec(dllexport) void display(double* arr, int size);
}