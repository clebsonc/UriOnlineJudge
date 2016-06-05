#include <iostream>

template <class T>
class Pair{
    private:
        T value1, value2;
    public:
        //constructor
        Pair();
        Pair(T v1, T v2);
        
        //destructor
        ~Pair();  //doesn't delete anything since we are not allocating any dynamic memory

        // Copy constructor
        Pair(const Pair& p){
            this->value1 = p.getValue1();
            this->value2 = p.getValue2();
        }
        
        // copy assignment
        Pair& operator= (const Pair & p){
            this->value1 = p.getValue1();
            this->value2 = p.getValue2();
            return *this;
        }

        // overload operator +
        Pair operator+ (Pair & p){  // I can't use the declaration as [ const Pair & p ] since the getters and setters are not const
        // const objects are supposed to only access const members functions
            Pair<T> temp;
            temp.setValue1(p.getValue1()+this->value1);
            temp.setValue2(p.getValue2()+this->value2);
            return temp;
        }


        //set functions
        void setValue1(T value1);
        void setValue2(T value2);

        //get functions
        T getValue1() const;
        T getValue2() const;

        // other non default functions
        void toString(); // this method should print the pair values
};


// Constructor
template <class  T>
Pair<T>::Pair(){}

template <class T>
Pair<T>::Pair(T v1, T v2){
    this->value1 = v1;
    this->valu2 = v2;
}


// Destructor
template <class T>
Pair<T>::~Pair(){
    //nothing to declare since no virtual memory was allocated
}


//Set functions
template <class T>
void Pair<T>::setValue1(T v){
    this->value1 = v;
}

template <class T>
void Pair<T>::setValue2(T v){
    this->value2 = v;
}


// get functions
template <class T>
T Pair<T>::getValue1() const{
    return this->value1;
}

template <class T>
T Pair<T>::getValue2() const{
    return this->value2;
}

template <class T>
void Pair<T>::toString(){
    std::cout << "Pair (" << this->getValue1() << ", " << this->getValue2() << ")" << std::endl;
}

/**
Author: Clebson
September 5, 2015
*/
int main(){
    int a, b;
    std::cin >> a >> b;
    Pair<int> my_pair1, my_pair2, my_pair3, my_pair5;
    my_pair1.setValue1(a);
    my_pair1.setValue2(b);
    std::cin.clear();
    fflush(stdin);
    std::cin >> a >> b;
    my_pair2.setValue1(a);
    my_pair2.setValue2(b);
    my_pair1.toString();
    my_pair2.toString();
    my_pair3 = my_pair2 + my_pair1;
    my_pair3.toString();
    
    Pair<int> my_pair4(my_pair3); // copy constructor is called
    my_pair4.toString();
    my_pair5 = my_pair2; // copy assignment is called
    my_pair5.toString();
    return 0;
}
