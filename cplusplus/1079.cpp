#include <iostream>
#include <list>
#include <array>

int main(){
    int a;
    std::cin >> a;
    std::list<std::array<double,3>> list_container;
    for(int i = 0; i < a; i++){
        std::array<double, 3> values;
        std::cin >> values[0] >> values[1] >> values[2];
        list_container.push_back(values);
    }
    for(std::list<std::array<double, 3>>::iterator it = list_container.begin(); it != list_container.end(); it++){
        printf("%.1f\n", (it->at(0) * 2 + it->at(1) * 3 + it->at(2) * 5)/(2 + 3 + 5));
    }


    return 0;
}
