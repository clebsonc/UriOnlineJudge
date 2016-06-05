#include <iostream>
#include <new>
#include <algorithm>

template <class T>
class Tree{
    protected:
        class Node;

        Node * root;

    public:
        Tree(): root(nullptr){}

        Node * getRoot(){ return this->root; }

        void insertNode(T value){
            if(root == nullptr){
                Node * nnode = new (std::nothrow) Node(nullptr,nullptr,value);
                if(nnode != nullptr)
                    root = nnode;
                else 
                    std::cout << "Error while allocating memory";
            }
            else if( value < root->getValue()){
                insertNode(root->getLeft(), value);
            }
            else{
                insertNode(root->getRight(), value);
            }
        }
        void insertNode(Node * & r, T value){
            if(r == nullptr){
                Node * nnode = new (std::nothrow) Node(nullptr,nullptr,value);
                if(nnode != nullptr)
                    r = nnode;
                else 
                    std::cout << "Error while allocating memory";
            }
            else if( value < r->getValue()){
                insertNode(r->getLeft(), value);
            }
            else{
                insertNode(r->getRight(), value);
            }
        }

        int findTreeHeight(){ return findTreeHeight(this->root); }

        int findTreeHeight(Node * const r){
            if(r == nullptr)
                return 0;
            return 1 +  std::max(findTreeHeight(r->getLeft()), findTreeHeight(r->getRight()) );
        }

        void deleteAllNodes(Node * & r){
            // delete the nodes in post order traversal
            if(r == nullptr)
                return;
            deleteAllNodes(r->getLeft());
            deleteAllNodes(r->getRight());
            std::cout << "Deleting: " << r->getValue() << std::endl;
            delete r;
            r = nullptr;
        }

        void printElements(){
            printElements(this->root);
        }
        void printElements(Node * const r){
            if(r == nullptr)
                return;
            else{
                // print elements traversing in pre-order
                std::cout << "Value: " << r->getValue() << std::endl;
                printElements(r->getLeft());
                printElements(r->getRight());
            }
        }


        int findCommonAncestor(int v1, int v2){
            return findCommonAncestor(this->root, v1, v2);
        }
        int findCommonAncestor(Node * const r, int v1, int v2){
            if(r==nullptr)
                return 0;
            if( v1 <= r->getValue() && v2 >= r->getValue() || r->getLeft() == nullptr && r->getRight() == nullptr)
                return r->getValue();
            if ( v1 <= r->getValue() && v2 <= r->getValue() )
                findCommonAncestor(r->getLeft(), v1, v2);
            else
                findCommonAncestor(r->getRight(), v1, v2);
        }

        ~Tree(){
            deleteAllNodes(this->root);
        }

};

template <class T>
class Tree<T>::Node{
    private:
        Node * left;
        Node * right;
        T value;

    public:
        // Constructors
        Node(): left(nullptr), right(nullptr){}
        Node(Node * l, Node * r, T v): left(l), right(r), value(v){};

        // Destructor
        ~Node(){}

        // getters
        Node * & getLeft(){ return this->left; }
        Node * & getRight(){ return this->right; }
        T getValue(){ return this->value; }

        // setters
        void setLeft(Node * const & l){ this->left = l; }
        void setRight(Node * const & r){ this->right = r; }
        void setValue(const T & v){ this->value = v; }
};

int main(){
    Tree<int> a;
    a.insertNode(20);
    a.insertNode(8);
    a.insertNode(4);
    a.insertNode(12);
    a.insertNode(10);
    a.insertNode(14);
    a.insertNode(22);
    std::cout << "printing" << std::endl;
    a.printElements();
    std::cout << "printing finished" << std::endl;

    std::cout << "The three height is: " << a.findTreeHeight() << std::endl;

    std::cout<< "Common Ancestor is: " << a.findCommonAncestor(9, 11) << std::endl;
    return 0;
}
