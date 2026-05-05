#include <iostream>
#include <cstring>
class Vehicle{
    protected:
        char* type;
    public:
        virtual void info() = 0;
        Vehicle(const char* t) {
            type = new char[std::strlen(t) +1];
            std::strcpy(type,t);
        }
        virtual ~Vehicle() {
            delete[] type;
        }

};
class Car : public Vehicle{
    protected:
        char* brand;
    public:
        Car(const char* t, const char* b) : Vehicle(t){
            brand = new char[strlen(b) +1 ];
            std::strcpy(brand, b);
        }
        virtual void info() override{
            std::cout << type << " " << brand << std::endl;
        }
        ~Car() {
            delete[] brand;
        }

};
class ElectricCar : public Car{
    protected:
        double mWh;
    public:
        ElectricCar(const char* t, const char* b, double mw) : Car(t,b), mWh(mw){}
        virtual void info() override{
            std::cout << "Type: " << type << "Brand: " << brand << "MwH" << mWh << std::endl;
        }
        ~ElectricCar(){};
};
int main(){
    ElectricCar myCar("Suv", "Tesla", 75);
    myCar.info();
    Car newCar("Sedan", "RR");
    newCar.info();
}