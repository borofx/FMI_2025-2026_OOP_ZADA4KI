#include <iostream>
#include <functional>
#include <cmath>

class increaser{
    public:
        increaser(int initial) : toAdd(initial) {}
        
        int operator()(int x){
            return toAdd + x;
        }
    private:
        int toAdd;
};
int inc(int x) { return x + 1; };

std::function<int(int)> repeated(unsigned k, std::function<int(int)> f){
    return [k, f](int x)
    {
        for (unsigned i = 0; i < k; ++i)
        {
            x = f(x);
        }
        return x;
    };
}

std::function<double(double)> maxf (std::function<double(double)> f, std::function<double(double)> g)
{
    return [f, g](double x)
    {
        return std::max(f(x), g(x));
    };
};

std::function<double(double)> derive (std::function<double(double)> f){
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
    std::cout << result;
}