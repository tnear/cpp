/*
Inheritance.cpp
https://www.w3schools.com/cpp/cpp_polymorphism.asp
*/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Animal
{
public:
    virtual string animalSound()
    {
        return "Generic";
    }
};

class Pig : public Animal
{
public:
    string animalSound() override
    {
        return "Pig";
    }
};

class Dog : public Animal
{
public:
    string animalSound() override
    {
        return "Dog";
    }
};

void basic()
{
    string sound;
    Animal *animal = new Pig();
    sound = animal->animalSound();
    assert(sound == "Pig");

    Animal *animal2 = new Dog();
    sound = animal2->animalSound();
    assert(sound == "Dog");

    Animal *animal3 = new Animal();
    sound = animal3->animalSound();
    assert(sound == "Generic");
}

void test()
{
    basic();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
