#include <iostream>
#include <string>

int main(){
    std::string a, b, c;
    std::cin >> a >> b >> c;
    if(a.compare("vertebrado")==0){
        if(b.compare("mamifero")==0){
            if(c.compare("onivoro")==0)
                std::cout << "homem" << std::endl;
            else
                std::cout << "vaca" << std::endl;
        } else{
            if(c.compare("carnivoro") == 0)
                std::cout << "aguia" << std::endl;
            else
                std::cout<<"pomba" << std::endl;
        }
    }else if(b.compare("inseto")==0){
        if(c.compare("hematofago")==0)
            std::cout << "pulga" << std::endl;
        else
            std::cout << "lagarta" << std::endl;
    }else if(c.compare("hematofago")==0)
        std::cout << "sanguessuga" << std::endl;
    else
        std::cout << "minhoca" << std::endl;


    return 0;
}
