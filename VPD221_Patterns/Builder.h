#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class MCComponent
{
public:
	virtual ~MCComponent() {}
	virtual string toString() = 0;
};


class Radio : public MCComponent
{
public:
	virtual string toString() override
	{
		return "Radio";
	}
};


class CD : public MCComponent
{
public:
	virtual string toString() override
	{
		return "CD";
	}
};

class Karaoke : public MCComponent
{
public:
	virtual string toString() override
	{
		return "Karaoke";
	}
};


class Subwoofer : public MCComponent
{
public:
	virtual string toString() override
	{
		return "Subwoofer";
	}
};


class VinilDisk : public MCComponent
{
public:
	virtual string toString() override
	{
		return "VinilDisk";
	}
};



class MusicCenter
{
	vector<MCComponent*> parts;

public:



	void addParts(MCComponent* component)
	{
		parts.push_back(component);
	}

	void info()
	{
		cout << "Music Center" << endl;
		cout << "------------" << endl;
		for (int i = 0; i < parts.size(); i++)
		{
			cout << i + 1 << ". " << parts[i]->toString() << endl;
		}
	}
};



class Builder
{
public:
	virtual~Builder() {}
	virtual void buildRadio()     = 0;
	virtual void buildCD()        = 0;
	virtual void buildKaraoke()   = 0;
	virtual void buildSubwoofer() = 0;
	virtual void buildVinilDisk() = 0;
	virtual void buildRazia() = 0;
};


class MCBuilder : public Builder
{
	MusicCenter* result;

public:

	MCBuilder() { this->reset(); }

	~MCBuilder() { delete result; }

	void reset()
	{
		result = new MusicCenter();
	}

	MusicCenter* getResult()
	{
		MusicCenter* product = result;
		this->reset();
		return product;
	}

	virtual void buildRadio()     override { result->addParts(new Radio()); }

	virtual void buildCD()        override { result->addParts(new CD()); }

	virtual void buildKaraoke()   override { result->addParts(new Karaoke()); }

	virtual void buildSubwoofer() override { result->addParts(new Subwoofer()); }

	virtual void buildVinilDisk() override { result->addParts(new VinilDisk()); }

	virtual void buildRazia() {}

};


class Director
{
	Builder* builder;

public:
	Director(Builder* builder = nullptr) : builder(builder) { }

	void changeBuilder(Builder* builder)
	{
		if (this->builder)
			delete this->builder;
		this->builder = builder;
	}

	void make(string type)
	{
		if (type == "miniMC")
		{
			this->builder->buildRadio();
			this->builder->buildCD();

		}

		if (type == "maxiMC")
		{
			this->builder->buildRadio();
			this->builder->buildCD();
			this->builder->buildKaraoke();
			this->builder->buildSubwoofer();
			this->builder->buildVinilDisk();
		}


	}
};


class ManualMusicCenter
{
	string manual = "Manual Music Center\n-----------------\n";

public:
	void addPunkt(string punct)
	{
		manual += punct;
	}

	string info()
	{
		return manual;
	}
};


class ManualMCBuilder : public Builder
{
	ManualMusicCenter* result;

public:

	ManualMCBuilder() { this->reset(); }

	void reset()
	{
		result = new ManualMusicCenter();
	}

	ManualMusicCenter* getResult()
	{
		ManualMusicCenter* product = result;
		this->reset();
		return product;
	}

	virtual void buildRadio()     override { result->addPunkt("For Radio press 1\n"); }

	virtual void buildCD()        override { result->addPunkt("For CD press 3\n"); }

	virtual void buildKaraoke()   override { result->addPunkt("For Karaoke press 1 and 4\n"); }

	virtual void buildSubwoofer() override { result->addPunkt("For Subwoofer press 2\n"); }

	virtual void buildVinilDisk() override { result->addPunkt("For VinilDisk set disk and press 8\n"); }

	virtual void buildRazia() {}

};




//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	string type = "maxiMC";
//
//	Director* director = new Director();
//	MCBuilder* mcBuilder = new MCBuilder();
//	director->changeBuilder(mcBuilder);
//	director->make(type);
//	MusicCenter* mcCenter = mcBuilder->getResult();
//	mcCenter->info();
//	cout << endl;
//
//	ManualMCBuilder* mmcBuilder = new ManualMCBuilder;
//	director->changeBuilder(mmcBuilder);
//	director->make(type);
//	ManualMusicCenter* mmc = mmcBuilder->getResult();
//	cout << mmc->info() << endl;
//
//
//}