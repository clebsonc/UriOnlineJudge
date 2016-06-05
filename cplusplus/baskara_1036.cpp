#include <iostream>
#include <cmath>

void compute_baskara(double a, double b, double c){
    double delta = pow(b, 2) - (4*a*c);
    if(delta < 0 || a == 0.0)
        printf("Impossivel calcular\n");
    else{
        printf("R1 = %.5f\n", (-b + sqrt(delta))/(2*a));
        printf("R2 = %.5f\n", (-b - sqrt(delta))/(2*a));
    }
}


int main(){
    double a, b, c;
    std::cin >> a >> b >> c;
    compute_baskara(a, b, c);
    
    return 0;
}

