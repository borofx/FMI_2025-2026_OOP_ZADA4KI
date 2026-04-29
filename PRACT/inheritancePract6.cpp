#include <iostream>

class firstBase{
    public:
        ~firstBase() { std::cout << "Bad example destructor" << std::endl; }
};

class firstDerived : public firstBase {
    public:
        ~firstDerived() {std::cout << "Bad derived example destr" << std::endl; }
};

class secondBase{
    public:
        virtual ~secondBase() {std::cout << "Good stuff!" << std::endl; }
};

class secondDerived : public secondBase{
    public: 
        virtual ~secondDerived() {std::cout << "Good stuff derived here!" << std::endl; }
};


int main()
{
    firstBase* f = new firstDerived();
    delete f;

    secondBase* s = new secondDerived();
    delete s;
}