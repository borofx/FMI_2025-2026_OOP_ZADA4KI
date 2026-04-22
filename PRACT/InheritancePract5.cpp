#include <iostream>

class Shape
{
public:
    virtual double area() = 0;
    virtual void describe() = 0;

    virtual ~Shape() {}
};

class Circle : public Shape
{
protected:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() override
    {
        return radius * 3.14159 * radius;
    }
    void describe() override
    {
        std::cout << "Circle with radius: " << radius << std::endl;
    }
};
class Rectangle : public Shape
{
protected:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() override
    {
        return width * height;
    }
    void describe() override
    {
        std::cout << "Rectangle with width: " << width << " and height: " << height << std::endl;
    }
};

int main()
{
    Shape *shapes[3];

    shapes[0] = new Circle(1.0);
    shapes[1] = new Rectangle(5.0, 2.0);
    shapes[2] = new Rectangle(7.0, 10);

    for (int i = 0; i < 3; i++)
    {
        shapes[i]->describe();
        std::cout << "Area: " << shapes[i]->area() << std::endl;
        delete shapes[i];
    }
}