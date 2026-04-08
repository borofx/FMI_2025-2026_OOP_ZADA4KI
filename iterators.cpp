#include <iostream>

class Range{
    private:
        int* data;
        int size;

    public:
    Range(int n) : size(n) {data = new int[n](); }

    Range(const Range& other) : size(other.size){
        data = new int[size];
        for(int i = 0; i < size; i++) data[i] = other.data[i];

    }
    Range& operator=(const Range& other){
        if(this != &other){
            delete[] data;
            size = other.size;
            data = new int[size];
            for(int i = 0; i < size; i++) data[i] = other.data[i];
        }
        return *this;
    }

    ~Range() {delete[] data;}

    class Iterator{
        int* ptr;
    public:
        Iterator(int* p) : ptr(p) {}
        int& operator*() {return *ptr; }
    };
};

int main(){

}