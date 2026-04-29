#include <iostream>

class Worker{
    protected:
        const char* name;
        double salary;
    public:
        Worker(const char* _name, double _salary)
            : name(_name), salary(_salary) {
            std::cout << "Worker constructed\n";
        }

        void printWorker() {
            std::cout << "Name: " << name << ", Salary: " << salary << "\n";
        }
};

class Developer : virtual public Worker{
    protected:
        const char* language;
    public:
        Developer(const char* _name, double _salary, const char* _language)
            : Worker(_name,_salary), language(_language) {
            std::cout << "Developer constructed\n";
        }

        void printDev() {
            std::cout << "Language: " << language << "\n";
        }
};

class Manager : virtual public Worker{
    protected: 
        int teamSize;
    public:
        Manager(const char* _name, double _salary, int _teamSize)
            : Worker (_name, _salary), teamSize(_teamSize) {
            std::cout << "Manager constructed\n";
        }

        void printManager() {
            std::cout << "Team size: " << teamSize << "\n";
        }
};

class TeamLead : public Developer, public Manager{
    public:
        TeamLead(const char* _name, double _salary,
                const char* _language, int _teamSize)
            : Worker(_name, _salary),
            Developer(_name, _salary, _language),
            Manager(_name, _salary, _teamSize) {
            std::cout << "TeamLead constructed\n";
        }

        void printAll() {
            printWorker();
            printDev();
            printManager();
        }
};

int main(){
    TeamLead tl("NAsko", 5000, "Cpp", 5);

    std::cout << "\n--- Danni ---\n";
    tl.printAll();
}