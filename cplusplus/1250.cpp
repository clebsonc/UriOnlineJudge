#include<iostream>
#include<vector>
#include<string>

class KiloMan{
    private:
        int shot_numbers;
        std::vector<int> height;
        std::string action;
    public:
        KiloMan();
        KiloMan(int);
        KiloMan(int, std::vector<int>, std::string);

        void setShotsNumber(int);
        void setHeight(std::vector<int>);
        void setAction(std::string);

        int getShotsNumber();
        std::vector<int> getHeight();
        std::string getAction();

        void printHits();
};

KiloMan::KiloMan(){
}

KiloMan::KiloMan(int sn){
    this->shot_numbers = (sn >= 0 ? sn : 1);
}

KiloMan::KiloMan(int sn, std::vector<int> h, std::string ac){
    this->shot_numbers = (sn >= 0 ? sn : 1);
    this->height = h;
    this->action = ac;
}

void KiloMan::setShotsNumber(int sn){
    this->shot_numbers = (sn >= 0 ? sn : 1);
}
void KiloMan::setHeight(std::vector<int>){
    this->height = height;
} 
void KiloMan::setAction(std::string ac){
    this->action = ac;
}

int KiloMan::getShotsNumber(){
    return this->shot_numbers;
}
std::vector<int> KiloMan::getHeight(){
    return this->height;
}
std::string KiloMan::getAction(){
    return this->action;
}

void KiloMan::printHits(){
    //std::cout << "Shot Numbers: " << this->shot_numbers << std::endl;
    int hits = 0;
    for(int i = 0; i<this->shot_numbers; i++){
        //std::cout << "Action: " << this->action.at(i) << std::endl;
        //std::cout << "Height: " << this->height.size() << std::endl;
        //std::cout << " Height: " << this->height.at(i) << std::endl;
        if(this->action.at(i) == 'S' && this->height.at(i) <= 2){
            hits += 1;
        } else if (this->action.at(i) == 'J' && this->height.at(i) > 2 ){
            hits += 1;
        }
    }
    std::cout << hits << std::endl;
}

int main(){
    int testCases;
    std::cin >> testCases;
    for(int i = 0; i < testCases; i++){
        int shots;
        std::cin >> shots;
        int v;
        std::vector<int> h;
        for(int j = 0; j < shots; j++){
            std::cin >> v;
            h.push_back(v);
        }
        std::string ac;
        std::cin >> ac;
        KiloMan man(shots, h, ac);
        man.printHits();
    }

    return 0;
}
