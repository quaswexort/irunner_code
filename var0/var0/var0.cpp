#include<iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	if (!in)
	{
		out.close();
		return 0;
	}
	if (in.eof())
	{
		in.close();
		out.close();
		return 0;
	}
	const int n = 100;
	int i = 0;
	long long arr[n];
	while (in >> arr[i])
	{
		if ((arr[i] > 1000000000) || (i >= n))
		{
			in.close();
			out.close();
			return 0;
		}
		i++;
	}
	if (i == 0)
	{
		in.close();
		out.close();
		return 0;
	}
	in.close();
	int* arr1 = new int[i];
	for (int q = 0; q < i; q++)
	{
		arr1[q] = 0;
		long long b;
		int c, m = 0;
		for (int k = 0; k < 10; ++k)
		{
			c = 0;
			b = arr[q];
			while (b > 0)
			{
				if (b % 10 == k) c++;
				b /= 10;
			}
			if ((c != 0) && (c >= m))
			{
				m = c;
				arr1[q] = k;
			}
		}
	}
	for (int q = 0; q < i; q++)
		for (int j = 0; j < i - q - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				long long temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				int temp1 = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp1;
			}
	out << arr[0] << ":" << arr1[0] << endl;
	for (int q = 1; q < i; q++)
	{
		if (arr[q - 1] != arr[q])
		{
			out << arr[q] << ":" << arr1[q] << endl;
		}
	}
	out.close();
	delete[] arr1;
	return 0;
}