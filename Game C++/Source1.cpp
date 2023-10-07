
Question 01

class Extended_Dictionary
{
private:
	Dictionary dictionary*;

	Extended_Dictionary()
	{
		dictionary* = new Dictionary();
	}

};

Question 02

//override insertion operator
ostream& operator<<(ostream& os, const Word& word)
{
	os << word.getName() << " " << word.getType() << " " << endl;
	return os;

}
//calling example
court << wordObject;



Extended_Dictionary Dict;
try
{
	Dict.findWord(word);
}
catch(const char* msg)
{
	cerr << msg << endl;
}



void Dictionary::saveDictionary(string fileName)
{
	fstream output_fstream;

	output_fstream.open(fileName + ".txt", std::ios_base::out);

	//checking if the file cannot be open, existing with the error
	if (output_fstream.is_open())
	{
		cerr << "failed to open the file" << fileName + ".txt" << endl;
		return;
	}

	//looping through the wordlist
	for (Word* wordObject : wordVector)
	{ 
		//name
		output_fstream << wordObject->getName() << endl;
		//type
		output_fstream << wordObject->getType() << endl;
		//definition
		output_fstream << wordObject->getDefinition() << endl;

		output_fstream << "" << endl; //blank line separation
	}

	output_fstream.close();

}



