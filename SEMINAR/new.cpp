#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        
        Node(T value) : data(value), next(nullptr) {}
    };
    
    Node* head;
    
public:
    class Iterator {
    private:
        Node* current;
        
    public:
        Iterator(Node* node) : current(node) {}
        
        T& operator*() {
            return current->data;
        }
        
        Iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }
        
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };
    
    LinkedList() : head(nullptr) {}
    
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void push_front(T value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    
    Iterator begin() {
        return Iterator(head);
    }
    
    Iterator end() {
        return Iterator(nullptr);
    }
    
    void print() {
        for (auto it = begin(); it != end(); ++it) {
            std::cout << *it << " -> ";
        }
        std::cout << "nullptr\n";
    }
};

int main(){
    LinkedList<int> list;
    
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    
    std::cout << "Linked List: ";
    list.print();
    
    std::cout << "Using iterator: ";
    for (auto it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    
    return 0;
}