#include <iostream>
#include <new>

/*template <class T>
class Element{
    private:
        T value;
        Element * next;
        Element * previous;
    public:
        // constructor
        Element():next(nullptr), previous(nullptr){};
        Element(T value, Element * next, Element * previous): value(value), next(next), previous(previous){}
        
        Element(const Element & other){ // copy constructor
            this->value = other.getValue();
            this->next = other.getNext();
            this->previous = other.getPrevious();
        }

        void operator= (const Element & other){ // copy assignment
            this->value = other.getValue();
            this->next = other.getNext();
            this->previous = other.getPrevious();
        }
        
        ~Element(){}  // lets pass the cleaning up to the header class, so it's not necessary to place anything on this destructor class

        //setters and getters
        void setValue(const T & value){ this->value = value; } // passing a const by reference
        void setNext(Element * n){ this->next = n; }
        void setPrevious(Element * p){ this->previous = p; }

        T getValue(){ return this->value; }
        Element * getNext(){ return this->next; }
        Element * getPrevious(){ return this->previous; }
};
*/
template <class T>
class DoubleLinkedList{
    protected:    
        class Element{
            private:
                T value;
                Element * next;
                Element * previous;
            public:
                // constructor
                Element():next(nullptr), previous(nullptr){};
                Element(T value, Element * next, Element * previous): value(value), next(next), previous(previous){}
                
                Element(const Element & other){ // copy constructor
                    this->value = other.getValue();
                    this->next = other.getNext();
                    this->previous = other.getPrevious();
                }

                void operator= (const Element & other){ // copy assignment
                    this->value = other.getValue();
                    this->next = other.getNext();
                    this->previous = other.getPrevious();
                }
                
                ~Element(){}  // lets pass the cleaning up to the header class, so it's not necessary to place anything on this destructor class

                //setters and getters
                void setValue(const T & value){ this->value = value; } // passing a const by reference
                void setNext(Element * n){ this->next = n; }
                void setPrevious(Element * p){ this->previous = p; }

                T getValue(){ return this->value; }
                Element * getNext(){ return this->next; }
                Element * getPrevious(){ return this->previous; }
        };
        Element * header;

    public:
        DoubleLinkedList(): header(nullptr){}  // default constructor
        
        ~DoubleLinkedList(){
            std::cout << "Releasing allocated memory. " << std::endl;
            if(header != nullptr){  // there is memory allocated
                Element * aux = header->getPrevious();
                while(aux!=nullptr && aux->getPrevious() != nullptr){
                    std::cout << "Cleaning value: " << aux->getValue() << std::endl;
                    aux = aux->getPrevious();
                    delete aux->getNext();
                }
                std::cout << "Cleaning value: " << aux->getValue() << std::endl;
                delete aux;
                aux = header->getNext();
                while(aux!=nullptr && aux->getNext() != nullptr){
                    std::cout << "Cleaning value: " << aux->getValue() << std::endl;
                    aux = aux->getNext();
                    delete aux->getPrevious();
                }
                std::cout << "Cleaning value: " << header->getValue() << std::endl;
                delete header;
            }
        }

        bool insertSorted(T value){
            Element * node = new (std::nothrow) Element; // call the default constructor
            if(node != nullptr){  // the element was successfully created
                node->setValue(value);
                if(header == nullptr){  // there isn't any element inserted on the linked list
                    header = node;
                    header->setNext(nullptr);
                    header->setPrevious(nullptr);
                } else if(value < header->getValue()){
                        while(value < header->getValue() && header->getPrevious() != nullptr && header->getPrevious()->getValue() > value)
                            header = header->getPrevious();
                        //insert the element
                        node->setNext(header);
                        node->setPrevious(header->getPrevious());
                        header->setPrevious(node);
                        if(node->getPrevious() != nullptr)
                            node->getPrevious()->setNext(node);
                } else{
                        while(value > header->getValue() && header->getNext() != nullptr && header->getNext()->getValue() < value)
                            header = header->getNext();
                        node->setNext(header->getNext());
                        node->setPrevious(header);
                        header->setNext(node);
                        if(node->getNext()!=nullptr)
                            node->getNext()->setPrevious(node);
                }
                return true; // insertion was a success
            }
            return false; // failure while allocating memory
        }

        void printOrder(){
            if(header != nullptr){  // there is data on the list
                while(header->getPrevious() != nullptr)
                    header = header->getPrevious();
                while(header->getNext() != nullptr){
                    std::cout << "Value: " << header->getValue() << std::endl;
                    header = header->getNext();
                }
                std::cout << "Value: " << header->getValue() << std::endl; // print the last data on the list
            }
        }

};

int main(){
    DoubleLinkedList<int> dll;
    dll.insertSorted(5);
    dll.insertSorted(3);
    dll.insertSorted(6);
    dll.insertSorted(15);
    dll.insertSorted(14);
    dll.insertSorted(2);
    dll.insertSorted(20);
    dll.insertSorted(1);
    dll.insertSorted(21);
    dll.printOrder();
    return 0;
}
