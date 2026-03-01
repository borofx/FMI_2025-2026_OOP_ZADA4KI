#include <iostream>

enum class FuelType
{
    Petrol,
    Diesel,
    Electric,
    Hybrid,
};

struct Car
{
    char brand[50];
    char model[50];
    int yearOfProduction;
    double price;
    FuelType fuel;
};

const char* fuelToString(FuelType fuel) {
    switch (fuel) {
        case FuelType::Petrol:   return "Petrol";
        case FuelType::Diesel:   return "Diesel";
        case FuelType::Electric: return "Electric";
        case FuelType::Hybrid:   return "Hybrid";
        default: return "Unknown";
    }
}


void printCar(const Car& car)
{   std::cout << "Brand: ";
    for(int i = 0; (car.brand[i]) != '\0'; i++)
    {
        std::cout << car.brand[i];
    }   std::cout << std::endl;

    std::cout << "Model: ";
    for(int i = 0; (car.model[i]) != '\0'; i++)
    {
        std::cout << car.model[i];
    }   std::cout << std::endl;

    std::cout << "Year of production: " << car.yearOfProduction << std::endl;

    std::cout << "Price " << car.price << std::endl;

    std::cout << "Fuel  " << fuelToString(car.fuel) << std::endl;

}

char* strduplicate (const char* str)
{
    if(str == nullptr)
        return nullptr;

    size_t length = 0;
    while(str[length] != '\0'){
        ++length;
    }

    char* copy = new char[length+1];

    for(size_t i = 0; i<length; ++i)
    {
        copy[i] = str[i];
    }

    copy[length] = '\0';

    return copy;
}

int main()
{
    const char* text = "Whatsup chiggas?!";

    char* duplicated = strduplicate(text);

    std::cout << duplicated << std::endl;

    delete[] duplicated;

    return 0;
}