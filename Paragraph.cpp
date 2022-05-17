#include "Paragraph.h"
Paragraph::Paragraph()
{
	arr = nullptr;
	words = nullptr;
	wordCount = 0;
	senCount = 0;
	uppercase = false;
	lowercase = false;
	encrypt = false;
}
Paragraph::Paragraph(const Paragraph& obj)
{
	int sentence = obj.getSenCount();
	if (sentence != 0)
	{
		wordCount = obj.wordCount;
		punCount = obj.punCount;
		uppercase = obj.uppercase;
		lowercase = obj.lowercase;
		encrypt = obj.encrypt;
		senCount = obj.senCount;
		arr = new char*** [1];
		arr[0] = new char** [obj.senCount];
		words = new int[senCount];
		for (int i = 0; i < senCount; i++)
		{
			words[i] = obj.words[i];
			arr[0][i] = new char* [obj.words[i]];
		}
		for (int i = 0; i < obj.senCount; i++)
		{
			for (int j = 0; j < words[i]; j++)
			{
				int size = strlen(obj.arr[0][i][j]);
				arr[0][i][j] = new char[size + 1];
				for (int k = 0; k < size; k++)
					arr[0][i][j][k] = obj.arr[0][i][j][k];
				arr[0][i][j][size] = '\0';
			}
		}
		
	}
	else
	{
		arr = nullptr;
		words = nullptr;
		wordCount = 0;
		senCount = 0;
		punCount = 0;
		uppercase = false;
		lowercase = false;
		encrypt = false;
	}
}
Paragraph& Paragraph::operator=(const Paragraph& obj)
{
	if (*this == obj)
		return *this;
	int countt = obj.getSenCount();
	if (countt = 0)
		return *this;
	uppercase = obj.uppercase;
	lowercase = obj.lowercase;
	encrypt = obj.encrypt;
	wordCount = obj.wordCount;
	punCount = obj.punCount;
	if (arr != nullptr)
	{
		for (int i = 0; i < senCount; i++)
		{
			for (int j = 0; j < words[i]; j++)
				delete[]arr[0][i][j];
			delete[]arr[0][i];
		}
		delete[] words;
	}
	senCount = obj.senCount;
	arr = new char*** [1];
	arr[0] = new char** [obj.senCount];
	words = new int[senCount];
	for (int i = 0; i < senCount; i++)
	{
		words[i] = obj.words[i];
		arr[0][i] = new char* [obj.words[i]];
	}
	for (int i = 0; i < obj.senCount; i++)
	{
		for (int j = 0; j < words[i]; j++)
		{
			int size = strlen(obj.arr[0][i][j]);
			arr[0][i][j] = new char[size + 1];
			for (int k = 0; k < size; k++)
				arr[0][i][j][k] = obj.arr[0][i][j][k];
			arr[0][i][j][size] = '\0';
		}
	}

	return *this;
}
Paragraph Paragraph::operator+(const Paragraph& obj)
{
	Paragraph temporary;
	temporary.arr = new char*** [1];
	temporary.arr[0] = new char** [senCount + obj.senCount];
	temporary.senCount = senCount + obj.senCount;
	temporary.words = new int[temporary.senCount];
	int j = 0;
	for (int i = 0; i < obj.senCount; i++, j++)
	{
		temporary.words[j] = obj.words[i];
		temporary.arr[0][j] = new char* [obj.words[i]];
	}
	for (int i = 0; i < senCount; i++, j++)
	{
		temporary.words[j] = words[i];
		temporary.arr[0][j] = new char* [words[i]];
	}
	int n = 0;
	int m = 0;
	for (int i = 0; i < obj.senCount; i++, m++)
	{
		for (int j = 0; j < obj.words[i]; j++, n++)
		{
			int size = strlen(obj.arr[0][i][j]);
			temporary.arr[0][m][n] = new char[size + 1];
			for (int k = 0; k < size; k++)
				temporary.arr[0][m][n][k] = obj.arr[0][i][j][k];
			temporary.arr[0][m][n][size] = '\0';
		}
		n = 0;
	}
	for (int i = 0; i < senCount; i++, m++)
	{
		for (int j = 0; j < words[i]; j++, n++)
		{
			int size = strlen(arr[0][i][j]);
			temporary.arr[0][m][n] = new char[size + 1];
			for (int k = 0; k < size; k++)
				temporary.arr[0][m][n][k] = arr[0][i][j][k];
			temporary.arr[0][m][n][size] = '\0';
		}
		n = 0;
	}
	return temporary;
}
Paragraph& Paragraph::operator++()
{
	for (int i = 0; i < senCount; i++)
	{
		for (int j = 0; j < words[i]; j++)
		{
			for (int k = 0; k < strlen(arr[0][i][j]); k++)
			{
				if (arr[0][i][j][k] < 123 && arr[0][i][j][k] > 96)
					arr[0][i][j][k] -= 32;
			}
		}
	}
	uppercase = true;
	lowercase = false;
	return*this;
}
Paragraph& Paragraph::operator--()
{
	for (int i = 0; i < senCount; i++)
	{
		for (int j = 0; j < words[i]; j++)
		{
			for (int k = 0; k < strlen(arr[0][i][j]); k++)
			{
				if (arr[0][i][j][k] < 91 && arr[0][i][j][k] > 64)
					arr[0][i][j][k] += 32;
			}
		}
	}
	uppercase = false;
	lowercase = true;
	return*this;
}
Paragraph Paragraph::operator++(int)
{
	Paragraph temp;
	temp = *this;
	return temp;
}
Paragraph Paragraph::operator--(int)
{
	Paragraph temp;
	temp = *this;
	return temp;
}
Paragraph& Paragraph::operator*(int a)
{
	if (!encrypt)
	{
		for (int i = 0; i < senCount; i++)
		{
			for (int j = 0; j < words[i]; j++)
			{
				for (int k = 0; k < strlen(arr[0][i][j]); k++)
					arr[0][i][j][k] += a;
			}
		}
		encrypt = true;
	}
	return *this;
}
Paragraph& Paragraph::operator%(int a)
{
	if (encrypt)
	{
		for (int i = 0; i < senCount; i++)
		{
			for (int j = 0; j < words[i]; j++)
			{
				for (int k = 0; k < strlen(arr[0][i][j]); k++)
					arr[0][i][j][k] -= a;
			}
		}
		encrypt = false;
	}
	return *this;
}
bool Paragraph::operator==(const Paragraph& obj)
{
	bool flag = false;
	if (senCount == obj.senCount)
	{
		for (int i = 0; i < senCount; i++)
		{
			if (words[i] == obj.words[i])
			{
				flag = true;
			}
		}
	}
	if (flag)
	{
		for (int i = 0; i < senCount; i++)
		{
			for (int j = 0; j < words[i]; j++)
			{
				for (int k = 0; arr[0][i][j][k] != '\0'; k++)
				{
					if (arr[0][i][j][k] == obj.arr[0][i][j][k])
						flag = true;
					else
					{
						flag = false;
						break;
					}
				}
				if (!flag)
					break;
			}
			if (!flag)
				break;
		}
	}
	return flag;
}
bool Paragraph::operator!=(const Paragraph& obj)
{
	bool flag = false;
	return flag;
}
char**** Paragraph::getArr()
{
	char**** temparray;
	temparray = new char*** [1];
	temparray[0] = new char** [senCount];
	for (int i = 0; i < senCount; i++)
	{
		temparray[0][i] = new char* [words[i]];
	}
	for (int i = 0; i < senCount; i++)
	{
		for (int j = 0; j < words[i]; j++)
		{
			int size = strlen(arr[0][i][j]);
			temparray[0][i][j] = new char[size + 1];
			for (int k = 0; k < size; k++)
				temparray[0][i][j][k] = arr[0][i][j][k];
			temparray[0][i][j][size] = '\0';
		}
	}
	return temparray;
}
int Paragraph::getPunCount()
{
	return punCount;
}
int Paragraph::getSenCount()const
{
	return senCount;
}
int* Paragraph::getWords()
{
	int* temp = new int[senCount];
	for (int i = 0; i < senCount; i++)
		temp[i] = words[i];
	return temp;
}
int Paragraph::getWordCount()
{
	return wordCount;
}
Paragraph::~Paragraph()
{
	if (arr != nullptr)
	{
		for (int i = 0; i < senCount; i++)
		{
			for (int j = 0; j < words[i]; j++)
				delete[]arr[0][i][j];
			delete[]arr[0][i];
		}
		delete[]words;
	}
}
void Paragraph::setArr(char**** temparray)
{
	if (senCount == 0)
	{
		cout << "Please set Sentence Counter first" << endl;
		if (words == nullptr)
			cout << "Also set Words first" << endl;
	}
	else
	{
		if (arr != nullptr)
		{
			for (int i = 0; i < senCount; i++)
			{
				for (int j = 0; j < words[i]; j++)
					delete[]arr[0][i][j];
				delete[]arr[0][i];
			}
			delete[]words;
		}
		arr = new char*** [1];
		arr[0] = new char** [senCount];
		for (int i = 0; i < senCount; i++)
			arr[0][i] = new char* [words[i]];
		for (int i = 0; i < senCount; i++)
		{
			for (int j = 0; j < words[i]; j++)
			{
				int size = strlen(temparray[0][i][j]);
				arr[0][i][j] = new char[size + 1];
				for (int k = 0; k < size; k++)
					arr[0][i][j][k] = temparray[0][i][j][k];
				arr[0][i][j][size] = '\0';
			}
		}
	}
}
void Paragraph::setWordCount(int a)
{
	wordCount = a;
}
void Paragraph::setSenCount(int a)
{
	senCount = a;
}
void Paragraph::setPunCount(int a)
{
	punCount = a;
}
void Paragraph::setWords(int* a)
{
	if (senCount == 0)
		cout << "Please set Sentence Counter first" << endl;
	else
	{
		if (words != nullptr)
			delete[]words;
		words = new int[senCount];
		for (int i = 0; i < senCount; i++)
		{
			words[i] = a[i];
		}
	}
}
void Paragraph::spellCheck()
{
	char* fileName;
	fileName = new char[100];
	cout << "Enter file name for the dicitionary : ";
	cin >> fileName;
	
	ifstream fin;
	fin.open(fileName);
	while (!fin.is_open())
	{
		cout << "File cannot be opened" << endl;
		cout << "Enter file name again : ";
		cin >> fileName;
		fin.open(fileName);
	}
	int counter = 0;
	char temp[100];
	char list[10000];
	for (int i = 0; i < senCount; i++)
	{
		for (int j = 0; j < words[i]; j++)
		{
			fin.close();
			fin.open(fileName);
			bool flag = false;
			for (int k = 0; !fin.eof(); k++)
			{
				fin >> temp;
				if (arr[0][i][j][0] > 64 && arr[0][i][j][0] < 91)
					temp[0] += 32;
				for (int l = 0; l < strlen(temp); l++)
				{
					if (arr[0][i][j][l] != temp[l])
					{
						flag = false;
						break;
					}
					else
						flag = true;
				}
				if (flag)
					break;
			}
			if (!flag)
			{
				for (int l = 0; l < strlen(arr[0][i][j]); l++)
				{
					list[counter] = arr[0][i][j][l];
					counter++;
				}
				list[counter] = '*';
				counter++;
			}
		}
	}
	if (counter)
	{
		cout << "Words that are incorrect : " << endl;
		for (int i = 0; i < counter - 1; i++)
		{
			if (list[i] == '*')
			{
				cout << endl;
				i++;
			}
			cout << list[i];
		}
	}
	else
		cout << "All the words are correct" << endl;
}

/* *** Task 4 *** */

void Paragraph::getFrequency()    
{
	cout << "Paragraph 1" << endl;
	cout << "Sentences in Paragraph 1 : " << senCount << endl;
	for (int i = 0; i < senCount; i++)
	{
		cout << "Words in sentence no " << i + 1 << " : " << words[i] << endl;
		for (int j = 0; j < words[i]; j++)
		{
			cout << "Characters in word no " << j + 1 << " in sentence no " << i + 1 << " : " << strlen(arr[0][i][j]) << endl;
		}
	}
}

ostream& operator<<(ostream& out, Paragraph& obj)
{
	int* words = obj.getWords();
	int senCount = obj.getSenCount();
	char**** arr = obj.getArr();
	for (int i = 0; i < senCount; i++)
	{
		for (int j = 0; j < words[i]; j++)
		{
			out << arr[0][i][j] << " ";
		}
	}
	return out;
}
ofstream& operator<<(ofstream& fout, Paragraph& obj)
{
	int* words = obj.getWords();
	int senCount = obj.getSenCount();
	char**** arr = obj.getArr();
	for (int i = 0; i < senCount; i++)
	{
		for (int j = 0; j < words[i]; j++)
		{
			fout << arr[0][i][j] << " ";
		}
	}
	return fout;
}
void operator>>(ifstream& fin, Paragraph& obj)
{
	int punCount = 0;
	char**** arr;
	int wordCount = 0;
	char* temparr = new char[10000];
	int* size = new int[1000];
	int k = 0;
	int senCount = 0;
	size[0] = 0;
	bool flag = false;
	for (int a = 0; !fin.eof(); a++)
	{
		char temp[100];
		fin >> temp;
		wordCount++;
		int len = strlen(temp);
		size[senCount]++;
		if (temp[len - 1] == '.')
		{
			senCount++;
			size[senCount] = 0;
		}
		else
			flag = false;
		for (int i = 0; i < len; i++, k++)
			temparr[k] = temp[i];
		temparr[k] = '~';
		k++;
	}
	temparr[k] = '\0';
	if (!flag)
		senCount++;
	for (int m = 0; temparr[m] != '\0'; m++)
	{
		if ((temparr[m] > 32 && temparr[m] < 48) || (temparr[m] > 57 && temparr[m] < 97))
			punCount++;
	}
	int* words;
	words = new int[senCount];
	for (int i = 0; i < senCount; i++)
	{
		words[i] = size[i];
	}
	arr = new char*** [1];
	arr[0] = new char** [senCount];
	for (int i = 0; i < senCount; i++)
	{
		arr[0][i] = new char* [words[i]];
	}
	k = 0;
	int counter = 0;
	for (int i = 0; i < senCount; i++)
	{
		for (int j = 0; j < words[i]; j++, k++, counter++)
		{
			int len = 0;
			for (int l = 0; temparr[k] != '~'; l++, k++)
			{
				len++;
			}
			arr[0][i][j] = new char[len + 1];
			for (int l = 0; l < len; l++, counter++)
				arr[0][i][j][l] = temparr[counter];
			arr[0][i][j][len] = '\0';
		}
	}
	obj.setPunCount(punCount);
	obj.setSenCount(senCount);
	obj.setWords(words);
	obj.setWordCount(wordCount);
	obj.setArr(arr);
}