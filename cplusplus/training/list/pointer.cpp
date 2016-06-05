#include <iostream>


int main(){
    int v1 = 5, v2 = 15;
    std::cout << "V1: " << v1 << std::endl;
    std::cout << "V2: " << v2 << std::endl;
    std::cout << "&V1: " << &v1 << std::endl;
    std::cout << "&V1: " << &v1 << std::endl;
    int * p1, * p2;
    std::cout << "&p1: " << &p1 << std::endl;
    std::cout << "&p2: " << &p2 << std::endl;
    std::cout << "*p1: " << *p1 << std::endl;
    std::cout << "*p2: " << *p2 << std::endl;
    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;

    p1 = &v1;
    std::cout << "p1: " << p1 << std::endl;
    p2 = &v2;
    std::cout << "p2: " << p2 << std::endl;
    *p1 = 10;
    std::cout << "*p1: " << *p1 << std::endl;
    std::cout << "p1: " << p1 << std::endl;
    *p2 = *p1;
    std::cout << "*p2: " << *p2 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    p1 = p2;
    std::cout << "*p1: " << *p1 << std::endl;
    std::cout << "p1: " << p1 << std::endl;
    *p1 = 20;
    std::cout << "*p1: " << *p1 << std::endl;
    std::cout << "*p2: " << *p2 << std::endl;
    std::cout << "V1: " << v1 << " V2: " << v2 << std::endl;
    return 0;
}
