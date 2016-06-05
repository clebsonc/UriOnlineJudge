#include<iostream>
#include<list>

int main(){
    std::list<std::pair<int, int> > values;
    int a, b;
    std::cin >> a >> b;
    while(a!=b){
        values.push_back(std::pair<int, int>(a, b));
        std::cin >> a >> b;
    }
    for(std::list< std::pair<int, int> >::iterator it=values.begin(); it!= values.end(); it++){
        if(it->first > it->second)
            std::cout << "Decrescente" << std::endl;
        else
            std::cout << "Crescente" << std::endl;
    }

    return 0;
}
