#include <iostream>

class Shape{
    public:
    virtual double area(){
        return 0.0;
    }
};
class Circle : public Shape{
    double radius;
    public: 
        Circle(double r) : radius(r){}

        double area() override{
            return 3.14159 * radius * radius;
        }
};
class Rectangle : public Shape{
    double w, h;
    public:
        Rectangle(double width, double height) : w(width), h(height){}

        double area() override{
            return w*h;
        }
};


int main() {
    Shape* s1 = new Circle(5.0);
    Shape* s2 = new Rectangle(4.0, 6.0);

    std::cout << "Circle: "     << s1->area() << std::endl;
    std::cout << "Rectangle: "  << s2->area() << std::endl;

    delete s1;
    delete s2;
    return 0;
}