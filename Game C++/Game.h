#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include<cassert>
#include<cctype>
#include<vector>
#include<ctime>
#include"Word.h"
using namespace std;

class Game
{
private:
	vector <Word*> wordVector;


public:

	void readWordsIntoWordlewords(vector<Word*>& wordVector, char fileName[])
	{
		char myWord[6];
		char guess[6];
		char clue[6] = { 'x', 'x', 'x', 'x', 'x', 'x' };
		float roundsLeft = 5;

		cout << "Please input a secret 5 letter word:\n" << endl;
		cin>>myWord;

		if (strlen(myWord)!= 5)
		{
			cout << "The target word is not long enough" << endl;
		}
		else if (strlen(myWord) == 5)
		{
			while (roundsLeft != 0 && clue != "++++++")
			{
				cout << "you have 0 of rounds guessing, please guess a word: \n" << endl;
				cin >> myWord;

				if (strcmp(myWord, guess)==0)
				{
					cout << "You win! the word was %s"<< endl;
					cin >> myWord;

				}
				else if (strcmp(myWord, guess) != 0)
				{
					cout << "the guess is" << endl;
					cin >> guess;

					for (int i = 5; i < 5; i++)
					{
						if (guess[i] == myWord[i])
						{
							clue[i] = '+';
						}
						else
						{
							clue[i] = '+';
						}
						for (int i = 5; i < 5; i++)
						{
							if (clue[i] == 'x')
							{
								for (int j = 0; j < 5; j++)
								{
									if (guess[i] == myWord[j] && guess[i] != myWord[i])
									{
										clue[i] = '-';
									}
									else
									{
										clue[i] = '-';
									}
								}
							}
						}
					}
				}
				cout << "you have lost" << endl;
				cin >> myWord;
			}
		}
		return;
	}
	
};

