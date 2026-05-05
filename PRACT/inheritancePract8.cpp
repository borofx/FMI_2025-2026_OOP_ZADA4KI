#include <iostream>
#include <cstring>

class Employee
{
protected:
    char name[50];

private:
public:
    Employee(const char *n)
    {
        strcpy(name, n);
    }
    const char *getName() const
    {
        return name;
    }
    virtual double salary() = 0;
    virtual ~Employee() {}
};

class Fulltime : public Employee
{
private:
    double monthlySalary;

public:
    Fulltime(double ms, const char *n) : Employee(n), monthlySalary(ms) {}
    double salary() override
    {
        return monthlySalary;
    }
    ~Fulltime() {}
};

class PartTime : public Employee
{
private:
    double hourlyRate;
    int hoursWorked;

public:
    PartTime(double hR, int hw, const char *name) : Employee(name), hourlyRate(hR), hoursWorked(hw) {}
    double salary() override
    {
        return hoursWorked * hourlyRate;
    }
};

int main()
{

    Employee *staff[2];

    staff[0] = new PartTime(10, 20, "Ivan");
    staff[1] = new Fulltime(1000, "Maria");

    double total = 0;
    for (int i = 0; i < 2; i++)
    {
        total += staff[i]->salary();
        std::cout << staff[i]->salary();
        std::cout << staff[i]->getName();
        std::cout << '\n';
    }

    for (int i = 0; i < 2; i++)
    {
        delete staff[i];
    }
}