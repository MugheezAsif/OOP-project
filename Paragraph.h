#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Paragraph
{
	char**** arr;
	int wordCount;
	int senCount;
	int punCount;
	int* words;
	bool uppercase;
	bool lowercase;
	bool encrypt;
public:
	Paragraph();
	Paragraph(const Paragraph&);
	Paragraph& operator=(const Paragraph&);
	Paragraph operator+(const Paragraph&);
	Paragraph& operator++();
	Paragraph& operator--();
	Paragraph operator++(int);
	Paragraph operator--(int);
	Paragraph& operator*(int);
	Paragraph& operator%(int);
	bool operator==(const Paragraph&);
	bool operator!=(const Paragraph&);
	char**** getArr();
	int getSenCount()const;
	int getPunCount();
	int* getWords();
	int getWordCount();
	void setArr(char****);
	void setWordCount(int);
	void setPunCount(int);
	void setSenCount(int);
	void setWords(int*);
	void getFrequency();        // Task 4
	void spellCheck();
	~Paragraph();
};
ostream& operator<<(ostream&, Paragraph&);
ofstream& operator<<(ofstream&, Paragraph&);
void operator>>(ifstream&, Paragraph&);