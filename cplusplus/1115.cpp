#include<iostream>
#include<list>

class Quadrante{
    private:
        int x, y;
    public:
        Quadrante();
        Quadrante(int, int);
        void setX(int);
        void setY(int);
        int getX();
        int getY();
        void printQuadrante();
};

Quadrante::Quadrante(){}
Quadrante::Quadrante(int x, int y): x{x}, y{y}{}

void Quadrante::setX(int x){
    this->x = x;
}

void Quadrante::setY(int y){
    this->y = y;
}

int Quadrante::getX(){
    return this->x;
}

int Quadrante::getY(){
    return this->y;
}

void Quadrante::printQuadrante(){
    if(this->x>0 && this->y>0)
        std::cout << "primeiro" << std::endl;
    else if(this->x > 0 && this->y<0)
        std::cout << "quarto" << std::endl;
    else if(this->x < 0 && this->y>0)
        std::cout << "segundo" << std::endl;
    else if(this->x < 0 && this->y<0)
        std::cout << "terceiro" << std::endl;
}

int main(){
    int a, b;
    std::list<Quadrante> data;
    do{
        std::cin >> a >> b;
        data.push_back(Quadrante(a, b));
    } while(a!=0 && b!=0);
    
    std::list<Quadrante>::iterator it = data.begin();
    for(it; it!=data.end(); it++){
        it->printQuadrante();
    }
    
    return 0;
}
