#include <iostream>

template <typename T>
class Ranger{
public:
    class iterator{
    public:
        iterator(T value, T step){
            this->value_ = value;
            this->step_ = step;
        }

        T operator*() const{
            return this->value_;
        }
        iterator& operator++(){
            value_ += step_;
            return *this;
        }
        bool operator!=(const iterator& other) const {
                return (this->value_ != other.value_);
        }
    private:
        T value_;
        T step_;
    };

        iterator begin() const{
            return iterator(start_, step_);
        }
        iterator end() const{
            return iterator(end_, step_);
        }
        Ranger(T start, T end, T step = 1) : start_(start), end_(end), step_(step) {}

    
private:
        T start_;
        T end_;
        T step_;
};

int main(){
    Ranger<int> range(1,6,2);
    for (int val : Ranger(1, 6)) 
    {
        std::cout << val << " "; 
    }
}