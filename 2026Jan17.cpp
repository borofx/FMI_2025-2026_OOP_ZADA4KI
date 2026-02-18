#include <iostream>
#include <string>

struct Student{
    std::string name;
    int age;
    double grade;
};

int main()
{
    Student s;
    std::cout << "Enter name" << '\n';
    std::cin >> s.name;
    std::cout << "Enter age" << '\n';
    std::cin >> s.age;
    std::cout << "Enter grade" << '\n';
    std::cin >> s.grade;
    std::cout << s.name << ' ' << s.age << ' ' << s.grade;
}
