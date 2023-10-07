#include "Extended_Dictionary.h"
#include "Word.h"
#include<string>
#include<algorithm>
#include<iostream>
#include<random>
#include<stdlib.h>

void Extended_Dictionary::Palindrome()
{
	string wordName;
	int length;
	bool flag;

	for (Word* wordObject : wordVector)
	{
		wordName = wordObject->getName();
		length = wordName.size();
		flag = true;

		for (int i = 0; i < length; i++)
		{
			if (wordName[i] != wordName[length - i - 1])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			wordObject->printName();
		}
	}
}

bool Extended_Dictionary::areAnagram(string str1, string str2)
{
	//get length of both strings
	int n1 = str1.length();
	int n2 = str2.length();

	//if the length of both strings is not same then they are cannot be anagrams
	if (n1 != n2)
		return false;

	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	//compaire sorted strings
	for (int i = 0; i < n1; i++)
		if (str1[i] != str2[i])
			return false;
	return true;

}

void Extended_Dictionary::Anagram(string word)
{
	string wordName;
	for (Word* wordObject : wordVector)
	{
		wordName = wordObject->getName();
		if (word == wordName)
		{
			continue;
		}
		if (areAnagram(word, wordName))
		{
			wordObject->printName();
		}
	}
}

void Extended_Dictionary::findWord(string word)
{
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	auto wordIterator = find_if(wordVector.begin(), wordVector.end(), [&word](Word* object) {string name = object->getName(); transform(name.begin(), name.end(), name.begin(), ::tolower); return name == word; });

	if (wordIterator != wordVector.end())
	{
		(*wordIterator)->printDefinition();
		return;
	}

	std::cout << "Word not found" << endl;

}

Word* Extended_Dictionary::generateRandomNoun()
{
	srand(time(NULL));
	Word* word;

	int random = rand() % wordVector.size();
	word = wordVector[random];

	while (word->getType() != "n")
	{
		int random = rand() % wordVector.size();
		word = wordVector[random];
	}
	return word;
}

void Extended_Dictionary::guessingGame()
{
	int guess = 0;
	string noun;
	Word* guessingWord = generateRandomNoun();
	string guessingWordName = guessingWord->getName();

	cout << guessingWord->getDefinition() << "Length of the word is" << guessingWordName.size() << endl;

	while (guess != 3)
	{
		cout << "Enter the noun you guess:";
		cin >> noun;
		if (noun == guessingWordName)
		{
			cout << "Congradualtions you guessed it right";
			break;
		}
		else
		{
			if (guess == 0)
			{
				cout << "incorrect the first letter is";
			}
			else if (guess == 1)
			{
				cout << "incorrect the second letter is";
			}
			else
			{
				cout << "Better luck next time, the word was" << guessingWordName << endl;
				break;
			}
			cout << guessingWordName[guess] << endl;
		}
		++guess;
	}
}