#pragma once
#include "Dictionary.h"

class Extended_Dictionary : public Dictionary
{
private:
	bool areAnagram(string str1, string str2);
	Word* generateRandomNoun();

public:
	void findWord(string word);
	void Palindrome();
	void Anagram(string word);
	void guessingGame();
};

