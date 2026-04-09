#include <iostream>

template <typename T>
class Node{
    public:
    T data;
    Node<T>* next;
    Node (T value) : data(value), next(nullptr){}
};

template <typename T>
class LinkedList{

private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}

    ~LinkedList(){
        Node<T>* current = head;
        while(current != nullptr){
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void push_front(T val){
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }
    void pop_front(){
        if(head == nullptr){
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void print() const{
        Node<T>* current = head;
        while(current != nullptr){
            std::cout << current -> data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }

    class Iterator{
        private:
            Node<T>* current;
        public:

    }
};
int main(){
    LinkedList<int> myList;
    myList.push_front(30);
    myList.push_front(20);
    myList.pop_front();
    myList.push_front(10);

    myList.print();
    return 0;
}