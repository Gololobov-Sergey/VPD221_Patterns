#pragma once
#include<iostream>
#include<string>

using namespace std;


class Transport
{
public:
	virtual ~Transport() {}
	virtual void delivery(string adress) = 0;
	virtual string getName() = 0;
};

class Truck : public Transport
{
public:
	virtual void delivery(string adress) override
	{
		cout << "Вантаж доставлено наземним способом за адресою " << adress << endl;
	}
	virtual string getName()override
	{
		return "Створено вантажівку. ";
	}
};

class Ship : public Transport
{
public:
	virtual void delivery(string adress) override
	{
		cout << "Вантаж доставлено морем в порт " << adress << endl;
	}
	virtual string getName()override
	{
		return "Створено корабель. ";
	}
};


class SpaceShip : public Transport
{
public:
	virtual void delivery(string adress) override
	{
		cout << "Вантаж доставлено на планету " << adress << endl;
	}
	virtual string getName()override
	{
		return "Створено космічний шатл. ";
	}
};


class Creator
{
public:
	virtual~Creator() {}
	virtual Transport* createTransport() = 0;
	Transport* create()
	{
		Transport* transport = this->createTransport();
		cout << transport->getName();
		return transport;
	}
};

class TruckCreator : public Creator
{
public:
	virtual Transport* createTransport() override
	{
		return new Truck();
	}
};

class ShipCreator : public Creator
{
public:
	virtual Transport* createTransport() override
	{
		return new Ship();
	}
};

class SpaceShipCreator : public Creator
{
public:
	virtual Transport* createTransport() override
	{
		return new SpaceShip();
	}
};


//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	/*Creator* creator = new TruckCreator;
//	Transport* tr1 = creator->create();
//
//	tr1->delivery("Миколаїв");
//
//
//	creator = new ShipCreator;
//	Transport* tr2 = creator->create();
//
//	tr2->delivery("Odessa");
//
//
//	creator = new SpaceShipCreator;
//	Transport* tr3 = creator->create();
//
//	tr3->delivery("Mars");*/
//
//
//	Creator* creator = nullptr;
//	int n;
//	cout << "1 - Truck, 2 - Ship, 3 - SpaceShip : ";
//	cin >> n;
//	switch (n)
//	{
//	case 2: creator = new ShipCreator; break;
//	case 3: creator = new SpaceShipCreator; break;
//	default: creator = new TruckCreator; break;
//	}
//	Transport* tr = creator->create();
//	tr->delivery("Mars");
//}