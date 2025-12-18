#ifndef MATRIX_H
#define MATRIX_H

struct Matrix
{
    int** data = nullptr;
    size_t cols = 0;
    size_t rows = 0;
};

void Construct(Matrix& mat, size_t cols, size_t rows);
void Destruct(Matrix& mat);
Matrix Copy(const Matrix& mat);
Matrix Add(const Matrix& a, const Matrix& b);
Matrix Sub(const Matrix& a, const Matrix& b);
Matrix Mult(const Matrix& a, const Matrix& b);
void Transposition(Matrix& mat);
bool operator==(const Matrix& a, const Matrix& b);

#endif