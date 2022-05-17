// OOP PROJECT.cpp : This file contains the 'main' function. Program execution begins and ends there.
// L1F20BSCS0539
// MUGHEEZ ASIF
// OOP SEMESTER FINAL PROJECT

#include <iostream>
#include <fstream>
#include "Paragraph.h"
using namespace std;
int main()
{
	Paragraph obj;
	Paragraph obj2;

	ifstream fin;
	fin.open("data.txt");

	fin >> obj;
	fin.close();
	fin.open("data2.txt");
	fin >> obj2;
	
	cout << obj << endl << endl << obj2 << endl;
    //std::cout << "Hello World!\n"; 
	return 0;
}

