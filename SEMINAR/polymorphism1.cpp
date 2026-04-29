#include <cstring>
#include <iostream>

class Employee{
    protected:
        char name[100];
    public:
        Employee(const char* n) {
            std::strcpy(name, n);
        }
        virtual double getSalary() const = 0;
        virtual void describe() const = 0;
        virtual Employee* clone() const = 0;
        virtual ~Employee() {}
};
class Developer : public Employee{
    protected:
        int yearsOfExperience;
        double baseSalary;
    public:
        Developer(const char* name, int yOE, double baseSal) :
        Employee(name), yearsOfExperience(yOE), baseSalary(baseSal) {}

        double getSalary() const override{
            return baseSalary * (1 + 0.05 * yearsOfExperience);
        }
        void describe() const override{
            std::cout << name << std::endl;
            std::cout << "years of exp: " << yearsOfExperience << std::endl;
            std::cout << "base salary: " << getSalary() << std::endl;
        }
        Employee* clone() const override { return new Developer(*this); }
};
class Manager : public Employee{
    protected:
        int teamSize;
        double baseSalary;
    public:
        Manager(const char* name, int tSize, double baseSal) :
        Employee(name), teamSize(tSize), baseSalary(baseSal) {}

        void describe() const override{
            std::cout << name << std::endl;
            std::cout << "team size: " << teamSize << std::endl;
            std::cout << "salary: " << getSalary() << std::endl;
        }
        double getSalary() const override{
            return baseSalary * (1 + 200 * teamSize);
        }
        Employee* clone() const override { return new Manager(*this);}
};
double totalPayFunds(Employee* employees[], int count){
    double sum = 0;
    for(int i = 0; i < count; ++i){
        sum += employees[i]->getSalary();
    }
    return sum;
}

int main(){
    // Developer vanko("Ivan", 5, 1200.00);
    // vanko.describe();
    Employee* employees[3];
    employees[0] = new Developer("vanko", 3, 1200.00);
    employees[1] = new Developer("Peppy", 0, 1200);
    employees[2] = new Manager("Iller", 2, 1000);

    for(int i = 0; i < 3; i++){ employees[i]->describe(); }

    std::cout << "total payroll: " << totalPayFunds(employees, 3) << std::endl;

    //prevent memory leak
    for(int i = 0; i < 3; i ++){
        delete employees[i];
        employees[i] = nullptr;
    }
}