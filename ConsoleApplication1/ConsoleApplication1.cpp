#include <iostream>
#include <functional>
std::function<double(double)> derive(std::function<double(double)> f) {
    return [f](double x)
        {
            return (f(x + 0.001) - f(x)) / 0.001;
        };
}

int main()
{
    std::function<double(double)> d1 = derive([](double x) -> double
        { return x * x; });
    double result = d1(2);
    std::cout << d1(1);
}