#pragma warning(disable : 4996)
#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream in("input.txt");
	ofstream out("output.txt");
	if (!in)
	{
		out.close();
		return 0;
	}
	long long border1 = 0, border2 = 0;
	if (in.eof())
	{
		in.close();
		out.close();
		return 0;
	}
	in >> border1;
	in >> border2;
	string str;
	getline(in, str); 
	getline(in, str);
	long long size = str.size();
	if ((border1 > border2) || (border1 < 1) || (border2 > size))
	{
		in.close();
		out.close();
		return 0;
	}
	if (size > 30000)
	{
		in.close();
		out.close();
		return 0;
	}
		char* stroka = new char[size + 1];
		strcpy(stroka, str.c_str());
		long long n = 0, temp;
		while (border1 + n < border2 - n)
		{
			temp = str[border1 - 1 + n];
			stroka[border1 - 1 + n] = stroka[border2 - 1 - n];
			stroka[border2 - 1 - n] = temp;
			n++;
		}
		out << stroka;
		delete[] stroka;
		in.close();
		out.close();
	return 0;
}