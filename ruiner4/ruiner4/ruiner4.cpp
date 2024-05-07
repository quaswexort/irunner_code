#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cctype>
#pragma warning(disable : 4996)

using namespace std;

void main()
{
	int i = 0, summa = 0, summa_1 = 0, summa_2 = 0, sum4 = 0;
	char number[30001];
	cin.get(number, 30001);
	int size = strlen(number);
	if (size > 30000)
	{
		exit(1);
	}
	int* mtr = new int[size];
	while (i < size)
	{
		if (!isdigit(number[i]))
		{
			delete[] mtr;
			exit(1);
		}
		char buf[2] = { number[i],'\0' };
		mtr[i] = atoi(buf);
		if (!(i % 2))
			summa += mtr[i];
		else
			summa_1 += mtr[i];
		i++;
	}
	summa_2 = summa + summa_1;
	sum4 = abs(summa - summa_1);
	if (!((mtr[size - 2] * 10 + mtr[size - 1]) % 4))
	{
		if (!(summa_2 % 9))
		{
			if (!(sum4 % 11))
				cout << 8;
			else
				cout << 5;
		}
		else
		{
			if (!(sum4 % 11))
				cout << 6;
			else
				cout << 2;
		}
	}
	else
	{
		if (!(summa_2 % 9))
		{
			if (!(sum4 % 11))
				cout << 7;
			else
				cout << 3;
		}
		else
		{
			if (!(sum4 % 11))
				cout << 4;
			else
				cout << 1;
		}
	}
	delete[] mtr;
	//return 0;
}