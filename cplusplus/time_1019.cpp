#include <iostream>

class Time{
    private:
        int seconds, minutes, hours;
    public:
        Time();
        Time(int, int, int);
        
        void setSeconds(int);
        void setMinutes(int);
        void setHours(int);

        int getSeconds();
        int getMinutes();
        int getHours();

        void conversorSeconds_hms(int);
       
};

Time::Time(){
    this->seconds = 0;
    this->minutes = 0;
    this->hours = 0;
}

Time::Time(int seconds, int minutes, int hours):seconds{seconds}, minutes{minutes}, hours{hours}{
}

void Time::setSeconds(int seconds){
    this->seconds = seconds >=0? seconds : 0;
}

void Time::setMinutes(int minutes){
    this->minutes = minutes >=0? minutes : 0;
}

void Time::setHours(int hours){
    this->seconds = seconds >=0? seconds : 0;
}

int Time::getSeconds(){
    return this->seconds;
}

int Time::getMinutes(){
    return this->minutes;
}

int Time::getHours(){
    return this->hours;
}


void Time::conversorSeconds_hms(int seconds){
    std::cout << seconds / 3600 << ":" << (seconds%3600)/60 << ":" << ((seconds%3600)%60);
}

int main(){
    int a;
    std::cin >> a;
    Time time;
    time.conversorSeconds_hms(a);
    std::cout << "\n";
    
    return 0;
} 
