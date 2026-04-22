#include <iostream>

class Base{
    protected:
        const char* message = "borsuk";
    public:
        Base(char* mess){
            std::cout << "Created object of Base" << std::endl;
            message = mess;
        }  
        ~Base(){
            std::cout << "Base removed" << std::endl;
        }
};

class Derived : public Base{
    public: 
        Derived(char* message) : Base(message){
            std::cout << "ballz creator" << std::endl;
        }
        ~Derived(){
            std::cout << "ballz destructor" << std::endl;
        }
};

int main(){
    std::cout << "------Creating-------" << std::endl;
    Derived d("henlow");
    std::cout << "-------Removal-------" << std::endl;
}