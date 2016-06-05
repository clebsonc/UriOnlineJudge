#include <iostream>
#include <new>
#include <iomanip>


class Student{
    private:
        int w1, w2, w3, w4;
        double sc1, sc2, sc3, sc4, final_exam;
    public:
         Student();
         Student(int, int, int, int, double, double, double, double);
        
         void setFinalExam(double);
         void setScore1(double);
         void setScore2(double);
         void setScore3(double);
         void setScore4(double);

         double getFinalExam();
         double getScore1();
         double getScore2();
         double getScore3();
         double getScore4();

         double computeAverage();
         double computeFinalAverage();
         
         void studentSituation(double);
};


Student::Student():w1{2}, w2{3}, w3{4}, w4{1}{}

Student::Student(int w1, int w2, int w3, int w4,
                double s1, double s2, double s3, double s4){
    this->w1 = (w1 >= 0.0 ? w1 : 0);
    this->w2 = (w2 >= 0.0 ? w2 : 0);
    this->w3 = (w3 >= 0.0 ? w3 : 0);
    this->w4 = (w4 >= 0.0 ? w4 : 0);
    this->sc1 = (s1 >= 0.0 ? s1 : 0);
    this->sc2 = (s2 >= 0.0 ? s2 : 0);
    this->sc3 = (s3 >= 0.0 ? s3 : 0);
    this->sc4 = (s4 >= 0.0 ? s4 : 0);
}

void Student::setFinalExam(double exam){
    this->final_exam = (exam >= 0.0 ? exam : 0.0);
}
void Student::setScore1(double s){
    this->sc1 = (s >= 0? s : 0.0);
}
void Student::setScore2(double s){
    this->sc2 = (s >= 0? s : 0.0);
}
void Student::setScore3(double s){
    this->sc3 = (s >= 0? s : 0.0);
}
void Student::setScore4(double s){
    this->sc4 = (s >= 0? s : 0.0);
}

double Student::getFinalExam(){
    return this->final_exam;
}
double Student::getScore1(){
    return this->sc1;
}
double Student::getScore2(){
    return this->sc2;
}
double Student::getScore3(){
    return this->sc3;
}
double Student::getScore4(){
    return this->sc4;
}

double Student::computeAverage(){
    return (this->w1 * this->sc1 +
            this->w2 * this->sc2 +
            this->w3 * this->sc3 +
            this->w4 * this->sc4)/
           (this->w1 + this->w2 + this->w3 + this->w4);
}

double Student::computeFinalAverage(){
    return (this->computeAverage() + this->getFinalExam()) / 2.0;
}

void Student::studentSituation(double grade){
    if(grade < 5.0)
        std::cout << "Aluno reprovado."<<std::endl;
    else if (grade < 7.0){
        std::cout << "Aluno em exame." <<std::endl;
        std::cin >> grade;
        this->setFinalExam(grade);
        std::cout << "Nota do exame: " << this->getFinalExam() << std::endl;
        if (this->computeFinalAverage() < 5){
            std::cout << "Aluno reprovado." << std::endl;
            std::cout << "Media final: " << this->computeFinalAverage() << std::endl;
        }
        else{
            std::cout << "Aluno aprovado." << std::endl;
            std::cout << "Media final: " << this->computeFinalAverage() << std::endl;
        }
    }
    else
        std::cout << "Aluno aprovado." << std::endl;
}


int main(){
    Student *a = new (std::nothrow) Student;
    double s1, s2, s3, s4;
    std::cout << std::fixed << std::setprecision(1);
    if(a == nullptr)
        std::cout << "Error while allocating memory.";
    else{
        std::cin >> s1 >> s2 >> s3 >> s4;
        a->setScore1(s1);
        a->setScore2(s2);
        a->setScore3(s3);
        a->setScore4(s4);
        std::cout << "Media: " << a->computeAverage() <<std::endl;
        a->studentSituation(a->computeAverage());
    }
    delete a;
    return 0;
}
