#include <iostream>
#include <string>
#include <cmath>

struct Student 
{
    std::string name;
    int age;
    double grade;
};

struct Point 
{
    double x;
    double y;
};

double distance(Point a, Point b) 
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct Rectangle 
{
    double width;
    double height;
};

double findRectangleArea(Rectangle rect) 
{
    return rect.width * rect.height;
}

double findRectanglePerimeter(Rectangle myRectangle) 
{
    return 2 * (myRectangle.width + myRectangle.height);
}


int main()
{
    Student first;
    Student second;
    Student third;
    Student fourth;
    Student ivancho;

    Student students[5] = { first,second,third,fourth,ivancho };

    for (int i = 0; i < 5; i++) {
        std::cout << "Enter student #" << i + 1 << " name " << '\n';
        std::cin >> students[i].name;
        std::cout << '\n';
        std::cout << "age " << '\n';
        std::cin >> students[i].age; 
        std::cout << '\n';
        std::cout << "grade " << '\n';
        std::cin >> students[i].grade;
    }
    int highestIndex = 0;
    for (int i = 0; i < 4; i++) {
        if (students[i].grade < students[i + 1].grade) {
            highestIndex = i + 1;
        }
    }


    /*Student s;
    std::cout << "Enter name" << '\n';
    std::cin >> s.name;
    std::cout << "Enter age" << '\n';
    std::cin >> s.age;
    std::cout << "Enter grade" << '\n';
    std::cin >> s.grade;
    std::cout << s.name << ' ' << s.age << ' ' << s.grade;*/

}