#include <iostream>

void MyAllocTwoBuffs(unsigned short** refShortBuf, double** refDblsBuf, int nLen) {
    // Allocate memory for the buffers
    *refShortBuf = new unsigned short[nLen];
    *refDblsBuf = new double[nLen];

    std::cout << "Memory allocated for both buffers." << std::endl;

    // Fill the buffers
    for (int i = 0; i < nLen; i++) {
        (*refShortBuf)[i] = i;
        (*refDblsBuf)[i] = i * 2.25;

        std::cout << "At index " << i << ", shortBuf is " << (*refShortBuf)[i] << " and dblsBuf is " << (*refDblsBuf)[i] << std::endl;
    }
}

int main() {
    unsigned short* shortBuf;
    double* dblsBuf;
    int len = 10;

    // Call the function
    MyAllocTwoBuffs(&shortBuf, &dblsBuf, len);

    // Print the values in the buffers
    for (int i = 0; i < len; i++) {
        std::cout << "shortBuf[" << i << "] = " << shortBuf[i] << ", dblsBuf[" << i << "] = " << dblsBuf[i] << std::endl;
    }

    // Don't forget to delete the buffers when you're done with them
    delete[] shortBuf;
    delete[] dblsBuf;

    std::cout << "Memory freed for both buffers." << std::endl;

    return 0;
}
