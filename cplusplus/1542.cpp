#include<iostream>
#include<list>
 
class Data{
    private:
        int a, b, c;
    public:
        Data();
        Data(int, int, int);
        void setA(int);
        void setB(int);
        void setC(int);
 
        int getA();
        int getB();
        int getC();
};
 
Data::Data(){
}
 
Data::Data(int a, int b, int c):a{a}, b{b}, c{c}{
}
 
void Data::setA(int a){
    this->a = a;
}
void Data::setB(int b){
    this->b = b;
}
void Data::setC(int c){
    this->c = c;
}
 
int Data::getA(){
    return this->a;
}
int Data::getB(){
    return this->b;
}
int Data::getC(){
    return this->c;
}
 
int main(){
    int a, b, c;
    std::list<Data> ldata;
 
    std::cin >> a;
    while(a!=0){
        std::cin >> b >> c;
        ldata.push_back(Data(a, b, c));
        std::cin >> a;
    }
    for(Data od: ldata){
        double pag = (float) od.getB() / (od.getC() - od.getA()) * od.getA() * od.getC();
        if(pag != 1)
            printf("%.0lf paginas\n", pag);
        else
            printf("%.0lf pagina\n", pag);
    }
        //fflush(stdin);
    return 0;
}
