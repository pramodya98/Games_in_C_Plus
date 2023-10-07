#pragma once
#include<string>
#include<vector>
#include<fstream>

#include "Word.h"
using namespace std;

class Dictionary
{
protected:
	vector<Word*>wordVector;

public:
	vector<Word*>getWordVector();
	void loadDictionary(string fileName);
	void findWord(string word);
	void findCharacter(char character, int noOfTimes);
	void qWithoutU();
};
