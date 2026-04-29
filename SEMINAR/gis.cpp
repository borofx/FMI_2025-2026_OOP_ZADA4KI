#include <iostream>
#include <functional>

class List{
    private:
        struct Node{
            int data;
            Node* next;
            Node(int value) : data(value), next(nullptr) {}
        };
        Node* head;
    public:
        List() : head(nullptr) {}
        ~List() {
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }}
        void push_front(int value) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
        }
        void for_each(std::function<void(int)> func) {
            Node* current = head;
            while (current) {
                func(current->data);
                current = current->next;
            }
        }
        List& operator=(const List& other) {
            if (this == &other) return *this; 
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            Node* currentOther = other.head;
            Node* lastNewNode = nullptr;
            while (currentOther) {
                Node* newNode = new Node(currentOther->data);
                if (!head) {
                    head = newNode;
                } else {
                    lastNewNode->next = newNode;
                }
                lastNewNode = newNode;
                currentOther = currentOther->next;
            }
            return *this;
        }
        int LastIndexOf(int value) {
            int index = -1;
            int currentIndex = 0;
            Node* current = head;
            while (current) {
                if (current->data == value) {
                    index = currentIndex;
                }
                current = current->next;
                currentIndex++;
            }
            return index;
        }
};

int main(){
    List lst;
    List lst2;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);

    lst2.push_front(1);
    lst2.push_front(3);
    lst2.push_front(2);

    lst.for_each([](int value) {
        std::cout << value << " ";
    });

    std::cout << '\n';
    lst2.for_each([](int value) {
        std::cout << value << " ";
    });
    std::cout << '\n';
    std::cout << lst.LastIndexOf(2) << std::endl;
    std::cout << '\n';
    std::cout << lst2.LastIndexOf(2) << std::endl;
}