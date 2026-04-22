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

    LinkedList& push_front(T val){
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
        return *this;
    }

    LinkedList& push(T val){
        Node<T>* newNode = new Node<T>(val);
        if(head == nullptr){
            head = newNode;
        } else {
            Node<T>* current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
        return *this;
    }
    
    LinkedList& pop_front(){
        if(head == nullptr){
            return *this;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return *this;
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
            Iterator(Node<T>* startNode) : current(startNode) {}
            T& operator*(){
                return current->data;
            }
            Iterator& operator++(){
                current = current->next;
                return *this;
            }
            bool operator!=(const Iterator& other) const{
                return current != other.current;
            }            
    };
            Iterator begin(){ return Iterator(head);}
            Iterator end() {return Iterator(nullptr);}
};
int main(){
    LinkedList<int> myList;
    myList.push_front(30);
    myList.push_front(20).push_front(30).pop_front().push_front(40);
    
    for(int val : myList){
        std::cout << val << ", ";
    }

    myList.print();
    return 0;
}