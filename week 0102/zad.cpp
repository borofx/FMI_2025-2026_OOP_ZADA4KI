#include <iostream>
#include <cstring>

enum Division{
    ASSASSIN,
    MEDIC,
    MAGE,
    TANK
};

enum Combat{
    UNKNOWN = -1,
    RANGE,
    MELEE,
    BOTH
};

struct Hero
{
    char* name;
    Division division;
    Combat combat;
};

void initHero(Hero& hero, const char* name, Division d, Combat c) {
    hero.name = new char[strlen(name) + 1];
    strcpy(hero.name, name);

    hero.division = d;
    hero.combat = c;
}

const char* divisionToString(Division d) {
    switch (d) {
        case ASSASSIN: return "ASSASSIN";
        case MEDIC: return "MEDIC";
        case MAGE: return "MAGE";
        case TANK: return "TANK";
        default: return "UNKNOWN";
    }
}

const char* combatToString(Combat c) {
    switch (c) {
        case RANGE: return "RANGE";
        case MELEE: return "MELEE";
        case BOTH: return "BOTH";
        case UNKNOWN: return "UNKNOWN";
        default: return "INVALID";
    }
}
void printHero(const Hero& hero) {
    std::cout << "Name: " << hero.name << std::endl;
    std::cout << "Division: " << divisionToString(hero.division) << std::endl;
    std::cout << "Combat: " << combatToString(hero.combat) << std::endl;
}
void freeHero(Hero& hero) {
    delete[] hero.name;
    hero.name = nullptr;
}

int main(){
    Hero borimechkata;
    initHero(borimechkata,"Borimechkov", TANK, MELEE);
    printHero(borimechkata);
    freeHero(borimechkata);
}
