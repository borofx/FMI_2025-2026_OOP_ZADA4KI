#include <iostream>

struct BankBalance{
    private:
        double value;
    public:
        double getValue(){
            return value;
        }
        void withdraw(double money){
            if(money < 0 || money > value){
                std::cout << "invalid operation\n";
            }
            value -= money;
        }
        void deposit(double money){
            value += money;
        }

};

int main()
{
    BankBalance mybalance;
}