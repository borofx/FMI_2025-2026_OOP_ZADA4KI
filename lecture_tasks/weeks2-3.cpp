#include <iostream>


class Time 
{
    int hours;
    int minutes;

    void normalize(){ //25h 130m -> 3h:10min

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
    }
    void setMinutes(int m){
        if(m < 0)
        {
            std::cout << "Cannot enter negative minutes";
            minutes = 0;
        }else{
            int bonusHours = minutes/60;
            setHours(hours + bonusHours);
            minutes = m % 60;
        }
               
    }
    void addMinutes(int m){
        setMinutes(minutes + m);
    }

    int getMinutesFromMidnight() const{
        return (hours * 60) + minutes;
    }
    bool operator<(const Time& other) const{
        return this->getMinutesFromMidnight() < other.getMinutesFromMidnight();
    }
    Time operator+(const Time& other) const
    {
        int combinedHours = this->hours + other.hours;
        int combinedMinutes = this->minutes + other.minutes;
        return Time(combinedHours, combinedMinutes);
    }
    Time operator-(const Time& other) const{
        int differenceInHours = this->hours - other.hours;
        int differenceInMinutes = this->minutes - other.minutes;
        return Time(differenceInHours, differenceInMinutes);
    }    
};

int main(){
    
}