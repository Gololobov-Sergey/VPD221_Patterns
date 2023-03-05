#include <iostream>

#include "Singleton.h"
#include "Prototype.h"

using namespace std;


void foo(Animal* animal)
{
	Animal* copyAnimal = animal->clone();
	copyAnimal->print();
}


int main()
{
	Animal* cat = new Cat("Vas`ka");
	//cat->print();

	Animal* dog1= new Dog("Bobik");
	Animal* dog2 = new Dog("Sharik");
	//dog->print();

	//foo(dog);

	PrototypeRegistry pr;
	pr.add(cat);
	pr.add(dog1);
	pr.add(dog2);


	Animal* animal = pr.getByName("Bobik");
	animal->print();
}