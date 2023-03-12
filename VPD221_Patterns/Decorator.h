#pragma once
#include <iostream>
#include <string>


using namespace std;



class Pizza
{
	string name;

public:

	Pizza(string name) : name(name) {}

	string getName() { return name; }

	virtual int getPrice() = 0;
};



class ItalianPizza : public Pizza
{
public:

	ItalianPizza() : Pizza("Itallian pizza") {}

	virtual int getPrice() override { return 150; }
};


class PizzaDecorator : public Pizza
{
protected:
	Pizza* pizza;

public:
	PizzaDecorator(string wrapper, Pizza* p) : Pizza(wrapper), pizza(p) {}

};


class Tomato : public PizzaDecorator
{
public:
	Tomato(Pizza* p) : PizzaDecorator(p->getName() + ", with tomato", p) {}
	virtual int getPrice() override { return pizza->getPrice() + 20; }
};

class Cheese : public PizzaDecorator
{
public:
	Cheese(Pizza* p) : PizzaDecorator(p->getName() + ", with cheese", p) {}
	virtual int getPrice() override { return pizza->getPrice() + 30; }
};



//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	Pizza* pizza = new ItalianPizza();
//	pizza = new Tomato(pizza);
//	pizza = new Cheese(pizza);
//	pizza = new Cheese(pizza);
//	pizza = new Tomato(pizza);
//
//	cout << "Name  : " << pizza->getName() << endl;
//	cout << "Price : " << pizza->getPrice() << endl;
//}