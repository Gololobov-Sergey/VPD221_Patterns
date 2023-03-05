#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Animal
{
protected:
	string name;

public:
	Animal(string name) :name(name) {}
	virtual ~Animal() {}
	string getName();
	virtual void print() = 0;

	virtual Animal* clone() = 0;
};


string Animal::getName()
{
	return name;
}


class Cat : public Animal
{
public:
	Cat(string name) : Animal(name) {}
	virtual void print() override;
	virtual Animal* clone() override;
};

void Cat::print()
{
	cout << "I`m Cat. My name " << name << endl;
}

Animal* Cat::clone()
{
	return new Cat(*this);
}


class Dog : public Animal
{
public:
	Dog(string name) : Animal(name) {}
	virtual void print() override;
	virtual Animal* clone() override;
};

void Dog::print()
{
	cout << "I`m Dog. My name " << name << endl;
}

Animal* Dog::clone()
{
	return new Dog(*this);
}


class PrototypeRegistry
{
	vector<Animal*> items;

public:
	void add(Animal* animal);
	Animal* getByName(string name);
};

void PrototypeRegistry::add(Animal* animal)
{
	items.push_back(animal);
}


Animal* PrototypeRegistry::getByName(string name)
{
	for (Animal* a : items)
	{
		if (a->getName() == name)
			return a->clone();
	}
	return nullptr;
}



//void foo(Animal* animal)
//{
//	Animal* copyAnimal = animal->clone();
//	copyAnimal->print();
//}


//int main()
//{
//	Animal* cat = new Cat("Vas`ka");
//	//cat->print();
//
//	Animal* dog1 = new Dog("Bobik");
//	Animal* dog2 = new Dog("Sharik");
//	//dog->print();
//
//	//foo(dog);
//
//	PrototypeRegistry pr;
//	pr.add(cat);
//	pr.add(dog1);
//	pr.add(dog2);
//
//
//	Animal* animal = pr.getByName("Bobik");
//	animal->print();
//}