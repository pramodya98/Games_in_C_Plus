#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#include "Dictionary.h"
#include "Word.h"

void Dictionary::loadDictionary(string fileName)
{
	string word;
	string type;
	string definition;
	string lineBreak;

	Word* wordObject;
	ifstream myFile(fileName);

	while (!myFile.eof())
	{
		getline(myFile, type);
		getline(myFile, word);
		getline(myFile, definition);
		wordObject = new Word(word, definition, type);

		wordVector.push_back(wordObject);

		getline(myFile, lineBreak);
	}
	//close the file
	myFile.close();
}
vector <Word*> Dictionary::getWordVector()
{
	return wordVector;
}

//seach to find the matching words
void Dictionary::findWord(string word)
{
	auto wordIterator = find_if(wordVector.begin(), wordVector.end(), [&word](Word* object) {return object->getName() == word; });

	if (wordIterator != wordVector.end())
	{
		(*wordIterator)->printDefinition();
		return;

	}
	std::cout << "Word not found" << endl;
}
void Dictionary::findCharacter(char character, int noOfTimes)
{
	int count;
	string wordName;
	for (Word* wordObject : wordVector)
	{
		wordName = wordObject->getName();

		count = std::count(wordName.begin(), wordName.end(), character);

		if (count > noOfTimes)
		{
			wordObject->printDefinition();
		}
	}
}

void Dictionary::qWithoutU()
{
	string wordName;
	for (Word* wordObject : wordVector)
	{
		wordName = wordObject->getName();
		for (int i = 0; i < wordName.length(); i++)
		{
			if ((wordName[i] == 'q' && i + 1 < wordName.length() && wordName[i + 1] != 'u') || (wordName[i] == 'q' && i + 1 >= wordName.length()))
			{
				wordObject->printDefinition();
				break;
			}
		}
	}
}