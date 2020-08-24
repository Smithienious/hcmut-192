/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 07: 07004_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Tue Apr 23 17:52:55 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07004_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

//---------------------------------------------------------------------------
/**
* CaesarMessage class definition
*/
class CaesarMessage
{
	char *textBuffer;

public:
	CaesarMessage();
	CaesarMessage(CaesarMessage &obj);
	~CaesarMessage();
	void encode(const char *_message, int _shift);
	void decode(int _shiftKey, char *&_textContainer);
};

/**
* CaesarMessage class implementation
*/

/* The default constructor */
CaesarMessage::CaesarMessage()
{
	// TODO
	this->textBuffer = nullptr;
}

/* The copy constructor */
CaesarMessage::CaesarMessage(CaesarMessage &obj)
{
	// TODO
	int n = strlen(obj.textBuffer);
	char *plainText = new char[n + 1];
	for (int i = 0; i < n; i += 1)
		plainText[i] = obj.textBuffer[i];
	plainText[n] = '\0';
	textBuffer = plainText;
}

/* The destructor */
CaesarMessage::~CaesarMessage()
{
	/* You have to tidy the dynamic memory, right?
	But, wait! What will happen if the textBuffer has been deleted already?
	Can that problem happen? When, why? And what is the solution? */
	delete[] this->textBuffer;
}

/* Encode the input message and then store the result in the textBuffer */
void CaesarMessage::encode(const char *_message, int _shift)
{
	/* Guide: Lower case all the characters and then do the shifting.
	Just encode the alphabet, ignore any others */
	// TODO
	string result;
	for (int i = 0; *(_message + i) != '\0'; i += 1)
	{
		if (*(_message + i) >= 97 && *(_message + i) <= 122)
			result += char((*(_message + i) + _shift - 97) % 26 + 97);
		if (*(_message + i) >= 65 && *(_message + i) <= 90)
			result += char((*(_message + i) + _shift - 65) % 26 + 97);
	}
	char *encodedText = new char[strlen(result.c_str()) + 1];
	strcpy(encodedText, result.c_str());
	textBuffer = encodedText;
}

/* Decode the textBuffer content and then store the result in the textContainer */
void CaesarMessage::decode(int _shiftKey, char *&_textContainer)
{
	// TODO
	string result;
	for (int i = 0; *(this->textBuffer + i) != '\0'; i += 1)
		result += char((*(this->textBuffer + i) - _shiftKey - 97 + 26) % 26 + 97);
	char *decodedText = new char[strlen(result.c_str()) + 1];
	strcpy(decodedText, result.c_str());
	_textContainer = decodedText;
}

/* Notice this function */
void process(CaesarMessage msg, int shiftKey, char *&container)
{
	msg.decode(shiftKey, container);
}

//---------------------------------------------------------------------------
bool codeCheck()
{
	const char *forbiddenKeyword[] = {"include"};
	fstream ifs;
	ifs.open("main.cpp", ios::in);
	if (ifs.fail())
		ifs.open(FILENAME, ios::in);
	if (ifs.fail())
		return true;
	ifs.seekg(0, ifs.end);
	int fileSize = ifs.tellg();
	ifs.seekg(0, ifs.beg);
	char *fileContent = new char[fileSize];
	ifs.read(fileContent, fileSize);
	ifs.close();
	*strstr(fileContent, "bool codeCheck() {") = '\0';
	char *todoSegment = strstr(fileContent, "// Begin implementation");
	int numberOfForbiddenKeyword = sizeof(forbiddenKeyword) / sizeof(const char *);
	for (int i = 0; i < numberOfForbiddenKeyword; i++)
	{
		if (strstr(todoSegment, forbiddenKeyword[i]))
			return false;
	}
	delete[] fileContent;
	return true;
}

int main(int argc, char *argv[])
{
	/*
	if (codeCheck() == false)
	{
		cout << "Forbidden-keyword rule violation." << endl;
		return -1;
	}
	*/
	// Section: read testcase
	///Student may comment out this section for local testing
	if (argc < 2)
		return 0;
	ifstream fileIn;
	try
	{
		fileIn.open(argv[1]);
		if (fileIn.fail())
			throw "Failed to open file.";
		int shift;
		fileIn >> shift;
		string line;
		string inputString;
		while (!fileIn.eof())
		{
			getline(fileIn, line);
			if (line.length() > 0)
				if (line[line.length() - 1] == 13)
					line.pop_back();
			inputString += line;
		}
		char *plainText = new char[strlen(inputString.c_str()) + 1];
		strcpy(plainText, inputString.c_str());
		char *decodedText;
		{
			CaesarMessage msg;
			msg.encode(plainText, shift);
			process(msg, shift, decodedText);
		}
		cout << decodedText;
		delete[] decodedText;
		delete[] plainText;
		fileIn.close();
	}
	catch (const char *errMsg)
	{
		cerr << errMsg;
	}
	// Endsection: read testcase
	//------------------------------------
	return 0;
}
