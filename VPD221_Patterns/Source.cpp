#include <iostream>
#include <Windows.h>

#include "Singleton.h"
#include "Prototype.h"
#include "FactoryMethod.h"
#include "Builder.h"
#include "Abstract Factory.h"
#include "Adapter.h"
#include "Decorator.h"
#include "Facade.h"
#include "Proxy.h"
#include "Bridge.h"

using namespace std;



int main()
{
	SetConsoleOutputCP(1251);

	Programmer* pr1 = new OfficeProgrammer(new CPP_Language());
	pr1->work();
	pr1->getMoney();
	cout << endl;

	pr1->setLanguage(new CSharp_Language());
	pr1->work();
	pr1->getMoney();
	cout << endl;


	Programmer* pr2 = new FreelanceProgrammer(new CPP_Language());
	pr2->work();
	pr2->getMoney();
	cout << endl;

	pr2->setLanguage(new CSharp_Language());
	pr2->work();
	pr2->getMoney();
	cout << endl;
}