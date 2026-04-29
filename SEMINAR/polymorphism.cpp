#include <iostream>
#include <cstring>

void print(const char* word){
    for(int i = 0; word[i] != '\0';i++){
        std::cout << word[i];
    }
    std::cout << '\n';
}
class Animal{
    public:
        virtual void speak() {std::cout << "..." << std::endl; }
        virtual Animal* clone() const = 0;
        virtual ~Animal() {}
};
class Dog : public Animal{
    private:
        const char* word = "bau";
    public:
        void speak() override { print(word); }
        Animal* clone() const override{ return new Dog(*this); }
        ~Dog(){}
};
class Cat : public Animal{
    private:
        const char* word = "meaow";
    public:
        void speak() override { print(word); }
        Animal* clone() const override{ return new Cat(*this); }
        ~Cat(){}
};


//bazov klas - animal + "speak" method -> derived animal classes - dog, cat etc. -> meow, woof -> main: Animal* animals[n] => animals[i] = new Cat(); for(animals[i]->speak())
int main(){
    Animal* animals[2];

    animals[0] = new Cat();
    animals[1] = new Dog();

    for(int i = 0; i < 2; i++){
       animals[i]->speak();
       delete animals[i];
       animals[i] = nullptr;
    }
    
}