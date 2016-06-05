#include <iostream>
#include <map>
#include <string>

int main(){
    std::map<int, std::string> months;
    months.insert(std::pair<int, std::string>(1, "January"));
    months[2] = "February";
    months[3] = "March";
    months[4] = "April";
    months[5] = "May";
    months[6] = "June";
    months[7] = "July";
    months[8] = "August";
    months[9] = "September";
    months[10] = "October";
    months[11] = "November";
    months[12] = "December";
    int n;
    std::cin >> n;
    std::cout << months[n] << std::endl;

    return 0;
}
