#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Logger
{
	string path = "log.txt";

	static Logger* instance;
	Logger() {}

public:
	static Logger* getInstance();
	void sendMessage(string message);
};


Logger* Logger::instance = nullptr;

Logger* Logger::getInstance()
{
	if (instance == nullptr)
		instance = new Logger;
	return instance;
}

void Logger::sendMessage(string message)
{
	ofstream out(path, ios::app);
	out << __DATE__ << " " << __TIME__ << " " << message << endl;
	out.close();
}



//int main()
//{
//	{
//		Logger* log1 = Logger::getInstance();
//		log1->sendMessage("Hello");
//		//
//		cout << log1 << endl;
//	}
//
//	Logger* log2 = Logger::getInstance();
//	log2->sendMessage("Hello");
//	cout << log2 << endl;
//}