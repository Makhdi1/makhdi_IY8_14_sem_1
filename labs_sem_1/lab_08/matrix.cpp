#include "matrix.h"

void Construct(Matrix& mat, size_t cols, size_t rows)
{
    Destruct(mat);

    mat.cols = cols;
    mat.rows = rows;

    if (cols > 0 && rows > 0)
    {
        mat.data = new int*[rows];
        for (size_t i = 0; i < rows; ++i)
        {
            mat.data[i] = new int[cols]();
        }
    }
}

void Destruct(Matrix& mat)
{
    if (mat.data != nullptr)
    {
        for (size_t i = 0; i < mat.rows; ++i)
        {
            delete[] mat.data[i];
        }
        delete[] mat.data;
        mat.data = nullptr;
    }
    mat.cols = 0;
    mat.rows = 0;
}

Matrix Copy(const Matrix& mat)
{
    Matrix result;
    Construct(result, mat.cols, mat.rows);

    for (size_t i = 0; i < mat.rows; ++i)
    {
        for (size_t j = 0; j < mat.cols; ++j)
        {
            result.data[i][j] = mat.data[i][j];
        }
    }

    return result;
}

Matrix Add(const Matrix& a, const Matrix& b)
{
    if (a.cols != b.cols || a.rows != b.rows)
    {
        return Matrix{};
    }

    Matrix result;
    Construct(result, a.cols, a.rows);

    for (size_t i = 0; i < a.rows; ++i)
    {
        for (size_t j = 0; j < a.cols; ++j)
        {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }

    return result;
}

Matrix Sub(const Matrix& a, const Matrix& b)
{
    if (a.cols != b.cols || a.rows != b.rows)
    {
        return Matrix{};
    }

    Matrix result;
    Construct(result, a.cols, a.rows);

    for (size_t i = 0; i < a.rows; ++i)
    {
        for (size_t j = 0; j < a.cols; ++j)
        {
            result.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }

    return result;
}

Matrix Mult(const Matrix& a, const Matrix& b)
{
    if (a.cols != b.rows)
    {
        return Matrix{};
    }

    Matrix result;
    Construct(result, b.cols, a.rows);

    for (size_t i = 0; i < a.rows; ++i)
    {
        for (size_t j = 0; j < b.cols; ++j)
        {
            result.data[i][j] = 0;
            for (size_t k = 0; k < a.cols; ++k)
            {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }

    return result;
}

void Transposition(Matrix& mat)
{
    if (mat.data == nullptr || mat.cols == 0 || mat.rows == 0)
    {
        return;
    }

    Matrix temp;
    Construct(temp, mat.rows, mat.cols);

    for (size_t i = 0; i < mat.rows; ++i)
    {
        for (size_t j = 0; j < mat.cols; ++j)
        {
            temp.data[j][i] = mat.data[i][j];
        }
    }

    Destruct(mat);
    mat = temp;
}

bool operator==(const Matrix& a, const Matrix& b)
{
    if (a.cols != b.cols || a.rows != b.rows)
    {
        return false;
    }

    for (size_t i = 0; i < a.rows; ++i)
    {
        for (size_t j = 0; j < a.cols; ++j)
        {
            if (a.data[i][j] != b.data[i][j])
            {
                return false;
            }
        }
    }

    return true;
}