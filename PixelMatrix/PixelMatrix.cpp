#include <vector>
#include <cstdint>
#include <iostream>

typedef uint16_t tPixel;

class PxlMatrix {

private:
    std::vector<std::vector<tPixel>> matrix;

public:
    PxlMatrix() {}

    void allocate(int rows, int cols) {
        matrix.resize(rows, std::vector<tPixel>(cols));
    }

    std::vector<tPixel>& GetRowPtr(int nY) {
        return matrix[nY];
    }

    void free() {
        for (auto& row : matrix) {
            row.clear();
            row.shrink_to_fit();
        }
        matrix.clear();
        matrix.shrink_to_fit();
    }
};
int main() {
    PxlMatrix pxlMatrix;
    pxlMatrix.allocate(10, 10);

    // Get a reference to the 5th row
    std::vector<tPixel>& row = pxlMatrix.GetRowPtr(5);

    // Modify the first pixel in the 5th row
    row[0] = 255;
    std::cout << row[0];

    return 0;
}