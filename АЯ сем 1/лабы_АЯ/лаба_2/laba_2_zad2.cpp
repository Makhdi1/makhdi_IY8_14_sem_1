#include <iostream>

using byte = unsigned char;

int main() {
    std::pair<byte, byte> positionA, positionB;
    
    std::cin>>positionA.first>>positionA.second;
    std::cin>>positionB.first>>positionB.second;

    bool ladya = (positionA.first == positionB.first) || (positionA.second == positionB.second);

    bool slon = std::abs(positionA.first - positionB.first) == std::abs(positionA.second - positionB.second);

    bool korol = (std::abs(positionA.first - positionB.first) <= 1) && (std::abs(positionA.second - positionB.second) <= 1);
    
    bool ferz = (positionA.first == positionB.first) || (positionA.second == positionB.second) || (std::abs(positionA.first - positionB.first) == std::abs(positionB.second));

    bool peshka = ((positionA.first == positionB.first) && (positionA.second == positionB.second + 1)) || (((positionA.first == positionB.first - 1) || (positionA.first == positionB.first + 1)) && (positionA.second == positionB.second + 1));
    
    bool peshka_hyper_hod = positionA.first == positionB.first && positionB.second - positionA.second == 1;
    
    if ( positionB.second - positionA.second == 1 && positionA.first == 1 && positionB.first == 2) {
        std::cout<<"jjj";
    } else {
        std::cout <<"johan" ;
    }
    
    // bool peshka_hyper_hod_i_mega_ataka = peshka_hyper_hod || peshka_mega_ataka;

    std::cout<<"Ladya ugrozhayet: "<<ladya<<std::endl;
    std::cout<<"Слон угрожает: "<<slon << std::endl;
    std::cout<< "Король может переместиться: "<<korol<<std::endl;
    std::cout<<"Ферзь ходит/угрожает: "<<ferz<<std::endl;
    // std::cout<<"Угроза высшего уровня пешка угрожает/ходит: "<<peshka_hyper_hod_i_mega_ataka<<std::endl;
    

    
}