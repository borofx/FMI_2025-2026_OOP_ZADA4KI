#include <iostream>



template <typename T>
void map(T arr[], int size, void (*func)(T)) {
    for (int i = 0; i < size; i++) {
        func(arr[i]);
    }
}

void print(int x){
    std::cout << x << " ";
}

void printDouble(double x){
    std::cout << x << " ";
}

void printSquareOfElement(int x){
    std::cout << x * x << " ";
}



int main(){
            
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = 5;

    map(arr1, size1, print);    
}