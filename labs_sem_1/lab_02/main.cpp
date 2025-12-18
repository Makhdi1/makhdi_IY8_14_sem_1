#include <iostream>
#include <utility>
#include <cmath>

int main() {
    // Task 1
    int X, Y, Z;
    std::cin >> X >> Y >> Z;

    bool condition1 = (X % 2 != 0) && (Y % 2 != 0);
    bool condition2 = ((X < 20) && (Y >= 20)) || ((X >= 20) && (Y < 20));
    bool condition3 = (X == 0) || (Y == 0);
    bool condition4 = (X < 0) && (Y < 0) && (Z < 0);

    int count5 = 0;
    if (X % 5 == 0) count5++;
    if (Y % 5 == 0) count5++;
    if (Z % 5 == 0) count5++;
    bool condition5 = (count5 == 1);

    bool condition6 = (X > 100) || (Y > 100) || (Z > 100);

    if (condition1 && condition2 && condition3 && condition4 && condition5 && condition6) {
        std::cout << "condition is true" << std::endl;
    } else {
        std::cout << "condition is false" << std::endl;
    }

    // Task 2
    using byte = unsigned char;
    std::pair<byte, byte> positionA;
    std::pair<byte, byte> positionB;

    std::cin >> positionA.first >> positionA.second;
    std::cin >> positionB.first >> positionB.second;

    int a = positionA.first;
    int b = positionA.second;
    int c = positionB.first;
    int d = positionB.second;

    // Rook
    bool rook_threat = (a == c) || (b == d);
    std::cout << "Rook threat: " << (rook_threat ? "yes" : "no") << std::endl;

    // Bishop
    bool bishop_threat = (std::abs(a - c) == std::abs(b - d));
    std::cout << "Bishop threat: " << (bishop_threat ? "yes" : "no") << std::endl;

    // King
    bool king_move = (std::abs(a - c) <= 1) && (std::abs(b - d) <= 1);
    std::cout << "King can move: " << (king_move ? "yes" : "no") << std::endl;

    // Queen
    bool queen_threat = rook_threat || bishop_threat;
    std::cout << "Queen threat: " << (queen_threat ? "yes" : "no") << std::endl;

    // White pawn
    bool pawn_normal = (a == c) && (d - b == 1);
    bool pawn_capture = (std::abs(a - c) == 1) && (d - b == 1);
    std::cout << "Pawn normal move: " << (pawn_normal ? "yes" : "no") << std::endl;
    std::cout << "Pawn capture: " << (pawn_capture ? "yes" : "no") << std::endl;

    // Task 3
    std::cout << "Multiplication table for 7:" << std::endl;
    for (int i = 1; i <= 9; i++) {
        std::cout << i << " x 7 = " << i * 7 << std::endl;
    }

    int N;
    std::cin >> N;
    std::cout << "Multiplication table for " << N << ":" << std::endl;
    for (int i = 1; i <= 9; i++) {
        std::cout << i << " x " << N << " = " << i * N << std::endl;
    }

    // Task 4
    int product1 = 1;
    for (int i = 8; i <= 15; i++) {
        product1 *= i;
    }
    std::cout << "Product from 8 to 15: " << product1 << std::endl;

    int a_val;
    std::cin >> a_val;
    int product2 = 1;
    for (int i = a_val; i <= 20; i++) {
        product2 *= i;
    }
    std::cout << "Product from " << a_val << " to 20: " << product2 << std::endl;

    int b_val;
    std::cin >> b_val;
    int product3 = 1;
    for (int i = 1; i <= b_val; i++) {
        product3 *= i;
    }
    std::cout << "Product from 1 to " << b_val << ": " << product3 << std::endl;

    int a_range, b_range;
    std::cin >> a_range >> b_range;
    int product4 = 1;
    for (int i = a_range; i <= b_range; i++) {
        product4 *= i;
    }
    std::cout << "Product from " << a_range << " to " << b_range << ": " << product4 << std::endl;

    return 0;
}