#include <iostream>

class Animal {
public:
    virtual void makeSound() { std::cout << "Some sound\n"; }
};

class Dog : public Animal {
public:
    void makeSound() override { std::cout << "Woof!\n"; }
};

int main() {
    Animal* animal = new Dog();
    animal->makeSound(); // "Woof!"
    delete animal;
    return 0;
}