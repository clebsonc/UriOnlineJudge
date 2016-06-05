#include <iostream>


class FuelSpent{
    private:
        const static float km_l;
        int time_spent;
        int average_velocity;
    public:
        //constructor
        FuelSpent();
        FuelSpent(int, int);
        
        //Functions
        float computeLitersHour();
};

const float FuelSpent::km_l = 12;

FuelSpent::FuelSpent(){}
FuelSpent::FuelSpent(int time, int velocity):time_spent{time},average_velocity{velocity}{
}

float FuelSpent::computeLitersHour(){
    return time_spent*average_velocity/FuelSpent::km_l;
}


int main(){
    int a, b;
    std::cin >> a >> b;
    FuelSpent fs(a, b);
    printf("%.3f\n",fs.computeLitersHour());

    return 0;
}
