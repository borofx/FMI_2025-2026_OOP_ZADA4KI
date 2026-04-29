#include <iostream>


class Time 
{
    int hours;
    int minutes;

    void normalize() // 25h 130m -> 3h 10m
    {
        hours += minutes / 60;
        minutes %= 60;

        hours %= 24;

        if (minutes < 0)
        {
            minutes += 60;
            hours--;
        }

        if (hours < 0)
        {
            hours += 24;
        }
    }

public:
    Time (int h = 0, int m = 0)
    {
        setHours(h);
        setMinutes(m);
    }

    int getHours() const
    {
        return hours;
    };

    int getMinutes() const {
        return minutes;
    };
    void setHours(int h) {
        if (h >= 0 && h < 24) {
            hours = h;
        } else {
            hours = 0; 
            std::cout << "Invalid hours entered. Setting to 0.\n";
        }
        normalize();
    }
    void setMinutes(int m)
    {
        minutes = m;
        normalize();
    }

    void addMinutes(int m){
        minutes += m;
        normalize();
    }

    int getMinutesFromMidnight() const{
        return (hours * 60) + minutes;
    }
    bool operator<(const Time& other) const{
        return this->getMinutesFromMidnight() < other.getMinutesFromMidnight();
    }
    Time operator+(const Time& other) const
    {
        int totalMinutes = this->getMinutesFromMidnight() + other.getMinutesFromMidnight();
        return Time(0, totalMinutes);
    }
    
    Time operator-(const Time& other) const
    {
        int totalMinutes = this->getMinutesFromMidnight() - other.getMinutesFromMidnight();
        return Time(0, totalMinutes);
    }    
    friend Time operator*(int n, const Time& t)
    {
        int totalMinutes = t.getMinutesFromMidnight() * n;
        return Time(0, totalMinutes);
    }
    void print() const{
        std::cout << hours<< ":";

        if(minutes < 10)
            std::cout << "0";

        std::cout << minutes << '\n';
    }

};

int main()
{
    Time t1(2, 50);
Time t2(1, 30);

Time sum = t1 + t2;   // 4:20
Time diff = t1 - t2;  // 1:20

t1.print();  // 2:50
t2.print();  // 1:30
sum.print(); // 4:20
diff.print();// 1:20
}