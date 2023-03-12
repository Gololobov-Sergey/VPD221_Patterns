#pragma once
#include <iostream>
#include <string>


using namespace std;


class ITransport
{
public:
	virtual void drive() = 0;
};



class Auto : public ITransport
{
public:
	void drive() override
	{
		cout << "Авто їде по дорозі" << endl;
	}
};



class Traveler
{
public:
	void travel(ITransport* transport)
	{
		transport->drive();
	}
};


class Camel
{
public:
	void move()
	{
		cout << "Верблюд іде по пустелі" << endl;
	}
};


class CamelAdapter : public ITransport
{

	Camel* camel;

public:

	CamelAdapter(Camel* camel) : camel(camel) {}

	void drive() override
	{
		camel->move();
	}
};


class Horse
{
public:
	void jamping()
	{
		cout << "Конячка скачить по степу" << endl;
	}
};


class HorseAdapter : public ITransport
{

	Horse* horse;

public:

	HorseAdapter(Horse* horse) : horse(horse) {}

	void drive()
	{
		horse->jamping();
	}
};


//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	Traveler* travaler = new Traveler;
//	travaler->travel(new Auto);
//
//	Camel* camel = new Camel;
//	CamelAdapter* ca = new CamelAdapter(camel);
//	travaler->travel(ca);
//
//
//	Horse* horse = new Horse;
//	HorseAdapter* ha = new HorseAdapter(horse);
//	travaler->travel(ha);
//}