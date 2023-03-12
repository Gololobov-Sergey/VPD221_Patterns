#pragma once
#include <iostream>
#include <string>


using namespace std;



class ILanguage
{
public:
	virtual ~ILanguage() {}
	virtual void build() = 0;
	virtual void execute() = 0;
};


class CPP_Language : public ILanguage
{
public:
	virtual void build() override
	{
		cout << "За допомогою компілятора створено бінарний файл (*.exe)" << endl;
	}

	virtual void execute() override
	{
		cout << "Запускаємо *.ехе файл" << endl;
	}
};


class CSharp_Language : public ILanguage
{
public:
	virtual void build() override
	{
		cout << "За допомогою компілятора Roslin створено CIL (*.exe)" << endl;
	}

	virtual void execute() override
	{
		cout << "Запускаємо JIT i компілюємо файл" << endl;
		cout << "Запускаємо *.ехе файл" << endl;
	}
};



class Programmer
{
	ILanguage* language = nullptr;

public:
	Programmer(ILanguage* language) : language(language)
	{

	}

	void setLanguage(ILanguage* language)
	{
		if (this->language)
			delete this->language;
		this->language = language;
	}

	void work()
	{
		this->language->build();
		this->language->execute();
	}

	virtual void getMoney() = 0;
};


class OfficeProgrammer : public Programmer
{
public:
	OfficeProgrammer(ILanguage* language) : Programmer(language)
	{

	}

	virtual void getMoney() override
	{
		cout << "Отримано ЗП в кінці місяця" << endl;
	}
};


class FreelanceProgrammer : public Programmer
{
public:
	FreelanceProgrammer(ILanguage* language) : Programmer(language)
	{

	}

	virtual void getMoney() override
	{
		cout << "Отримано ЗП в за виконану роботу" << endl;
	}
};


//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	Programmer* pr1 = new OfficeProgrammer(new CPP_Language());
//	pr1->work();
//	pr1->getMoney();
//	cout << endl;
//
//	pr1->setLanguage(new CSharp_Language());
//	pr1->work();
//	pr1->getMoney();
//	cout << endl;
//
//
//	Programmer* pr2 = new FreelanceProgrammer(new CPP_Language());
//	pr2->work();
//	pr2->getMoney();
//	cout << endl;
//
//	pr2->setLanguage(new CSharp_Language());
//	pr2->work();
//	pr2->getMoney();
//	cout << endl;
//}