#pragma once
#include <iostream>
#include <string>


using namespace std;


class Editor
{
public:
	void createCode() { cout << "������ ���" << endl; }
	void saveCode() { cout << "�������� ���" << endl; }
};


class Compiler
{
public:
	void compile() { cout << "��������� ���" << endl; }
};


class Debugger
{
public:
	void debug() { cout << "�������� ���" << endl; }
	void exit() { cout << "�����" << endl; }
};


class VS2022
{
	Editor* ed;
	Compiler* comp;
	Debugger* debug;

public:
	VS2022()
	{
		ed = new Editor();
		comp = new Compiler();
		debug = new Debugger();
	}

	void F5()
	{
		ed->createCode();
		ed->saveCode();
		comp->compile();
		debug->debug();
		debug->exit();
	}
};


//int main()
//{
//	SetConsoleOutputCP(1251);
//
//	VS2022* vs = new VS2022;
//	vs->F5();
//}