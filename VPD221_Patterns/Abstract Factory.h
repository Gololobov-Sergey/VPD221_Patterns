#pragma once
#include <iostream>
#include <string>


using namespace std;



class CarComponent
{
public:
	virtual ~CarComponent() {}
	virtual string toString() = 0;
};



class Engine : public CarComponent
{

};


class Transmission : public CarComponent
{

};

class BodyType : public CarComponent
{

};



class DiselEngine : public Engine
{

public:
	virtual string toString() override { return "Disel Engine"; }
};


class PetrolEngine : public Engine
{

public:
	virtual string toString() override { return "Petrol Engine"; }
};


class ElecrticEngine : public Engine
{

public:
	virtual string toString() override { return "Elecrtic Engine"; }
};


class MechanicTransmission : public Transmission
{

public:
	virtual string toString() override { return "Mechanic Transmission"; }
};


class AutomaticTransmission : public Transmission
{

public:
	virtual string toString() override { return "Automatic Transmission"; }
};


class VariatorTransmission : public Transmission
{

public:
	virtual string toString() override { return "Variator Transmission"; }
};


class SedanBodyType : public BodyType
{

public:
	virtual string toString() override { return "Sedan BodyType"; }
};


class UniversalBodyType : public BodyType
{

public:
	virtual string toString() override { return "Universal BodyType"; }
};


class CupeBodyType : public BodyType
{

public:
	virtual string toString() override { return "Cupe BodyType"; }
};



class Car
{
	Engine* engine;
	Transmission* transmission;
	BodyType* bodyType;
	string model;

public:
	~Car()
	{
		if (engine) delete engine;
		if (transmission) delete transmission;
		if (bodyType) delete bodyType;
	}


	void setEngine(Engine* engine) { this->engine = engine; }
	void setTransmission(Transmission* transmission) { this->transmission = transmission; }
	void setBodyType(BodyType* bodyType) { this->bodyType = bodyType; }
	void setModel(string model) { this->model = model; }

	void info()
	{
		cout << "Model        : " << model << endl;
		cout << "Engine       : " << engine->toString() << endl;
		cout << "Transmission : " << transmission->toString() << endl;
		cout << "BodyType     : " << bodyType->toString() << endl;
	}
};



class ICarFactory
{
public:
	virtual Engine*       createEngine() = 0;
	virtual Transmission* createTransmission() = 0;
	virtual BodyType*     createBodyType() = 0;
	virtual string        createModel() = 0;
};



class Tesla_Model_S_Factory : public ICarFactory
{
public:
	virtual Engine* createEngine()             override { return new ElecrticEngine; };

	virtual Transmission* createTransmission() override { return new VariatorTransmission; };

	virtual BodyType* createBodyType()         override { return new SedanBodyType; };

	virtual string        createModel()        override { return "Tesla Model S"; };
};


class Client
{
	ICarFactory* factory;

public:
	Client(ICarFactory* factory = nullptr) : factory(factory) { }

	~Client()
	{
		delete factory;
	}

	void setFactory(ICarFactory* factory)
	{
		if (this->factory)
			delete this->factory;
		this->factory = factory;
	}

	void create(Car* car)
	{
		car->setEngine(this->factory->createEngine());

		car->setTransmission(this->factory->createTransmission());

		car->setBodyType(this->factory->createBodyType());

		car->setModel(this->factory->createModel());
	}

};



class BMW_X7_Factory : public ICarFactory
{
public:
	virtual Engine* createEngine()             override { return new DiselEngine; };

	virtual Transmission* createTransmission() override { return new MechanicTransmission; };

	virtual BodyType* createBodyType()         override { return new UniversalBodyType; };

	virtual string        createModel()        override { return "BMW X7"; };
};



//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	Car* car1 = new Car;
//
//	Client* client = new Client(new Tesla_Model_S_Factory);
//
//	client->create(car1);
//
//	car1->info();
//
//	cout << endl;
//
//
//	Car* car2 = new Car;
//
//	client->setFactory(new BMW_X7_Factory);
//
//	client->create(car2);
//
//	car2->info();
//}