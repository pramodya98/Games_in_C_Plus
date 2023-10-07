#include "Word.h"
#include <iostream>
#include<string>
#include<algorithm>

using namespace std;

Word::Word(string name, string definition, string type)
{
	this->name = name;
	this->definition = definition;
	this->type = type;
}

string Word::getName()
{
	return name;
}
string Word::getDefinition()
{
	return definition;
}
string Word::getType()
{
	return type;
}

void Word::printDefinition()
{
	cout << name << " " << printType() << " " << endl;

	char* ptr, * next;
	int n = definition.length();

	char* definition_array = new char[n + 1];
	strcpy_s(definition_array, n + 1, definition.c_str());

	ptr = strtok_s(definition_array, ";", &next);

	while (ptr != NULL)
	{
		cout << ptr << endl;
		ptr = strtok_s(NULL, ";", &next);
	}
}

string Word::printType()
{
	if (type == "n")
	{
		return"Noun";
	}
	else if (type == "v")
	{
		return"Verb";
	}
	else if (type == "adv")
	{
		return"Adverb";
	}
	else if (type == "adj")
	{
		return"Adjective";
	}
	else if (type == "misc")
	{
		return"Miscellaneous";
	}
	else if (type == "pn")
	{
		return"Proper Noun";
	}
	else if (type == "prep")
	{
		return"Preposition";
	}
	else
	{
		return "Noun and verb";
	}

	return "\n" + type + "";
}
void Word::printName()
{
	cout << name;
}