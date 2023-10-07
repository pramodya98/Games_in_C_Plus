#include "Extended_Dictionary.h"
#include"Word.h"
#include"Game.h"

#include<string>
#include<iostream>
#include<fstream>
using namespace std;

Extended_Dictionary Dict;

//validate the user inputs
int validate(int input, string message)
{
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "you have entered wrong input" << endl;
			cout << message;
			cin >> input;
		}
		if (!cin.fail())
			return input;
	}
}

int main()
{
	string word, record, anagram;

	int noOfTimes;
	int character;
	int myWord;

	int task = 0;

	Dict.loadDictionary("dictionary_2022S2.txt");
	
	while (task != 8)
	{
		cout << "----------Menu---------" << endl << endl;
		cout << "    1 - Find a definition of a word " << endl;
		cout << "    2 - Find words with specific characters " << endl;
		cout << "    3 - list words that have a 'q' without following a 'u' " << endl;
		cout << "    4 - List all the words which are palindromes " << endl;
		cout << "    5 - Find words that are anagrams  " << endl;
		cout << "    6 - Guessing Game   " << endl;
		cout << "    7 - Wordle Game   " << endl;
		cout << "    8 - end " << endl;
		cout << "Enter -: ";

		cin >> task;

		task = validate(task, "Enter Task: ");

		switch (task)
		{
		case 1:
		{
			cout << "Enter word: ";
			cin >> word;
			Dict.findWord(word);
			break;
		}
		case 2:
		{
			cout << "Enter character: ";
			cin >> character;
			cout << "Enter minimum nuber of times: ";
			cin >> noOfTimes;
			noOfTimes = validate(noOfTimes, "Enter minimum number of times: ");
			Dict.findCharacter(character, noOfTimes);
			break;
		}
		case 3:
		{
			Dict.qWithoutU();
			break;
		}
		case 4:
		{
			Dict.Palindrome();
			break;
		}
		case 5:
		{
			cout << "Enter word: ";
			cin >> anagram;
			Dict.Anagram(anagram);
			break;
		}
		case 6:
		{
			Dict.guessingGame();
			break;
		}
		case 7:
		{
			cout << "To get started, enter your first 5 letter word.You have 6 attemps to guess the random word." << endl;
			cout << "please enter word: " << endl;
			cin >> myWord;
			break;
		}
		case 8:
		{
			cout << "Ending";
			break;
		}
		default:
		{
			cout << "Unknown Input";
			break;
		}
		}

	}
}