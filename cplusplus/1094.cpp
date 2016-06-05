#include <iostream>
#include <map>
#include <iomanip>

int main(){
    std::cout << std::fixed << std::setprecision(2);
    int a, b;
    char c;
    std::map<char, int> experiments;
    std::map<char, int>::iterator it;
    std::cin >> a;
    
    for(int i = 0; i < a; i++){
        std::cin >> b >> c;
        it = experiments.find(c);
        if(it != experiments.end()){
            experiments.at(c) = experiments.at(c)+b;
        } else{
            experiments.insert(std::pair<char, int>(c, b));
        }
    }
    
    it = experiments.begin();
    int total = 0;
    for(it; it!=experiments.end(); it++){
        total += (*it).second;
    }
    std::cout << "Total: " << total << " cobaias" << std::endl;
    std::cout << "Total de coelhos: " << experiments.find('C')->second << std::endl;
    std::cout << "Total de ratos: " << experiments.find('R')->second << std::endl;
    std::cout << "Total de sapos: " << experiments.find('S')->second << std::endl;
    std::cout << "Percentual de coelhos: " << experiments.find('C')->second*100.0/total << " %" << std::endl;
    std::cout << "Percentual de ratos: " << experiments.find('R')->second*100.0/total << " %" << std::endl;
    std::cout << "Percentual de sapos: " << experiments.find('S')->second*100.0/total << " %" << std::endl;

    return 0;
}
