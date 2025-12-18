#include "strings.h"
#include "matrix.h"
#include <iostream>

int main() {
    std::cout << "=== Strings Demo ===" << std::endl;
    
    const char* str1 = "Hello";
    const char* str2 = "World";
    
    char* copied = CopyString(str1);
    std::cout << "Copied: " << copied << std::endl;
    delete[] copied;
    
    char* combined = ConcatinateStrings(str1, str2);
    std::cout << "Concatenated: " << combined << std::endl;
    delete[] combined;
    
    std::cout << "\n=== Matrix Demo ===" << std::endl;
    
    Matrix m1;
    Construct(m1, 2, 2);
    m1.data_[0][0] = 1;
    m1.data_[0][1] = 2;
    m1.data_[1][0] = 3;
    m1.data_[1][1] = 4;
    
    Matrix m2;
    Construct(m2, 2, 2);
    m2.data_[0][0] = 5;
    m2.data_[0][1] = 6;
    m2.data_[1][0] = 7;
    m2.data_[1][1] = 8;
    
    Matrix sum = Add(m1, m2);
    std::cout << "Sum matrix:" << std::endl;
    for (size_t i = 0; i < sum.m_; i++) {
        for (size_t j = 0; j < sum.n_; j++) {
            std::cout << sum.data_[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    Matrix product = Mult(m1, m2);
    std::cout << "Product matrix:" << std::endl;
    for (size_t i = 0; i < product.m_; i++) {
        for (size_t j = 0; j < product.n_; j++) {
            std::cout << product.data_[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    Transposition(m1);
    std::cout << "Transposed m1:" << std::endl;
    for (size_t i = 0; i < m1.m_; i++) {
        for (size_t j = 0; j < m1.n_; j++) {
            std::cout << m1.data_[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    Destruct(m1);
    Destruct(m2);
    Destruct(sum);
    Destruct(product);
    
    return 0;
}