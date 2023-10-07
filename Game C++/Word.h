#pragma once
#include<string>

using namespace std;
class Word
{
private:
	string name;
	string type;
	string definition;

public:
	Word(string name, string definition, string type);

	string getName();
	string getDefinition();
	string getType();

	void printDefinition();
	string printType();
	void printName();
};

