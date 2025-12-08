#include <iostream>
#include <cstring>

// === Assignment 1 ===

char* CopyString(const char* str) {
    if (!str) return nullptr;
    
    size_t len = 0;
    while (str[len] != '\0') len++;
    
    char* newStr = new char[len + 1];
    for (size_t i = 0; i <= len; i++) {
        newStr[i] = str[i];
    }
    
    return newStr;
}

char* ConcatinateStrings(const char* a, const char* b) {
    if (!a || !b) return nullptr;
    
    size_t lenA = 0, lenB = 0;
    while (a[lenA] != '\0') lenA++;
    while (b[lenB] != '\0') lenB++;
    
    char* result = new char[lenA + lenB + 1];
    
    for (size_t i = 0; i < lenA; i++) result[i] = a[i];
    for (size_t i = 0; i <= lenB; i++) result[lenA + i] = b[i];
    
    return result;
}

// === Assignment 2 ===

struct Matrix {
    int** data_ = nullptr;
    size_t n_ = 0u;
    size_t m_ = 0u;
};

void Construct(Matrix& out, size_t n, size_t m) {
    out.n_ = n;
    out.m_ = m;
    out.data_ = new int*[m];
    
    for (size_t i = 0; i < m; i++) {
        out.data_[i] = new int[n];
        for (size_t j = 0; j < n; j++) {
            out.data_[i][j] = 0;
        }
    }
}

void Destruct(Matrix& in) {
    if (in.data_) {
        for (size_t i = 0; i < in.m_; i++) {
            delete[] in.data_[i];
        }
        delete[] in.data_;
        in.data_ = nullptr;
    }
    in.n_ = 0;
    in.m_ = 0;
}

Matrix Copy(const Matrix& matrix) {
    Matrix result;
    if (!matrix.data_) return result;
    
    Construct(result, matrix.n_, matrix.m_);
    
    for (size_t i = 0; i < matrix.m_; i++) {
        for (size_t j = 0; j < matrix.n_; j++) {
            result.data_[i][j] = matrix.data_[i][j];
        }
    }
    
    return result;
}

Matrix Add(const Matrix& a, const Matrix& b) {
    Matrix result;
    if (a.n_ != b.n_ || a.m_ != b.m_) return result;
    
    Construct(result, a.n_, a.m_);
    
    for (size_t i = 0; i < a.m_; i++) {
        for (size_t j = 0; j < a.n_; j++) {
            result.data_[i][j] = a.data_[i][j] + b.data_[i][j];
        }
    }
    
    return result;
}

Matrix Sub(const Matrix& a, const Matrix& b) {
    Matrix result;
    if (a.n_ != b.n_ || a.m_ != b.m_) return result;
    
    Construct(result, a.n_, a.m_);
    
    for (size_t i = 0; i < a.m_; i++) {
        for (size_t j = 0; j < a.n_; j++) {
            result.data_[i][j] = a.data_[i][j] - b.data_[i][j];
        }
    }
    
    return result;
}

Matrix Mult(const Matrix& a, const Matrix& b) {
    Matrix result;
    if (a.n_ != b.m_) return result;
    
    Construct(result, b.n_, a.m_);
    
    for (size_t i = 0; i < a.m_; i++) {
        for (size_t j = 0; j < b.n_; j++) {
            result.data_[i][j] = 0;
            for (size_t k = 0; k < a.n_; k++) {
                result.data_[i][j] += a.data_[i][k] * b.data_[k][j];
            }
        }
    }
    
    return result;
}

void Transposition(Matrix& matrix) {
    if (!matrix.data_) return;
    
    int** transposed = new int*[matrix.n_];
    for (size_t i = 0; i < matrix.n_; i++) {
        transposed[i] = new int[matrix.m_];
        for (size_t j = 0; j < matrix.m_; j++) {
            transposed[i][j] = matrix.data_[j][i];
        }
    }
    
    Destruct(matrix);
    matrix.data_ = transposed;
    std::swap(matrix.n_, matrix.m_);
}

bool operator==(const Matrix& a, const Matrix& b) {
    if (a.n_ != b.n_ || a.m_ != b.m_) return false;
    
    for (size_t i = 0; i < a.m_; i++) {
        for (size_t j = 0; j < a.n_; j++) {
            if (a.data_[i][j] != b.data_[i][j]) return false;
        }
    }
    
    return true;
}

int main() {
    // === Assignment 1 ===
    char* copy = CopyString("Hello");
    std::cout << "Copy: " << copy << std::endl;
    delete[] copy;
    
    char* concat = ConcatinateStrings("Hello", "World");
    std::cout << "Concat: " << concat << std::endl;
    delete[] concat;
    
    // === Assignment 2 ===
    Matrix mat1, mat2;
    Construct(mat1, 2, 2);
    Construct(mat2, 2, 2);
    
    mat1.data_[0][0] = 1; mat1.data_[0][1] = 2;
    mat1.data_[1][0] = 3; mat1.data_[1][1] = 4;
    
    mat2.data_[0][0] = 5; mat2.data_[0][1] = 6;
    mat2.data_[1][0] = 7; mat2.data_[1][1] = 8;
    
    Matrix sum = Add(mat1, mat2);
    std::cout << "Sum: " << sum.data_[0][0] << "," << sum.data_[0][1] 
              << "," << sum.data_[1][0] << "," << sum.data_[1][1] << std::endl;
    
    Matrix product = Mult(mat1, mat2);
    std::cout << "Product: " << product.data_[0][0] << "," << product.data_[0][1] 
              << "," << product.data_[1][0] << "," << product.data_[1][1] << std::endl;
    
    Destruct(mat1);
    Destruct(mat2);
    Destruct(sum);
    Destruct(product);
    
    return 0;
}