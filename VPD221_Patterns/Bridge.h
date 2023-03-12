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
		cout << "�� ��������� ���������� �������� ������� ���� (*.exe)" << endl;
	}

	virtual void execute() override
	{
		cout << "��������� *.��� ����" << endl;
	}
};


class CSharp_Language : public ILanguage
{
public:
	virtual void build() override
	{
		cout << "�� ��������� ���������� Roslin �������� CIL (*.exe)" << endl;
	}

	virtual void execute() override
	{
		cout << "��������� JIT i ��������� ����" << endl;
		cout << "��������� *.��� ����" << endl;
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
		cout << "�������� �� � ���� �����" << endl;
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
		cout << "�������� �� � �� �������� ������" << endl;
	}
};