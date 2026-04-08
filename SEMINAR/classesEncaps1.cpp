#include <iostream>
#include <cstring>

class String{

private:
    char* data;
    int length;

    void copyFrom(const String& other){
        length = other.length;
        data = new char[length+1];
        std::strcpy(data,other.data);
    }
    void free(){
        delete [] data;
        data = nullptr;
        length = 0;
    }
public:
    String(const char* str = ""){
        length = std::strlen(str);
        data = new char[length +1];
        std::strcpy(data,str);

        std::cout << " [Constructor] \"" << data << "\"" << std::endl;
    }

    String(const String& other){
        copyFrom(other);
        std::cout << "  [Copy ctor] \"" << data << "\"" << std::endl;    
    }

    String& operator=(const String& other){
        if(this != &other){
            free();
            copyFrom(other);
        }
        std::cout << "  [operator=] \"" << data << "\"" << std::endl;
        return *this;

    }
    ~String(){
        std::cout << " [destr]\"" << (data ? data : "null") << "\"" ;
        free();
    }
    const char* c_str() const { return data; }
    int getLength() const { return length; }

};

int main() {
    std::cout << "--- Създаване ---" << std::endl;
    String a("HIIII");         // Конструктор
    
    std::cout << "--- Копиране ---" << std::endl;
    String b = a;              // Copy constructor
    
    std::cout << "--- Присвояване ---" << std::endl;
    String c("World");         // Конструктор
    c = a;                     // operator=
    
    std::cout << "--- Край на main ---" << std::endl;
    return 0;

}