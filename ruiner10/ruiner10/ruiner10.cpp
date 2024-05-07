//#include<iostream>
//#include <fstream>
//using namespace std;
//void rsort(long long* array, long long* arr1, long long* arr2, long long size)
//{
//	if (!array || !size)
//		return;
//	long long jump = size;
//	bool swapped = true;
//	while (jump > 1 || swapped)
//	{
//		if (jump > 1)
//			jump = (long long)(jump / 1.25);
//		swapped = false;
//		for (long long i = 0; i + jump < size; i++)
//		{
//			if (array[i] > array[i + jump])
//			{
//				long long temp = array[i];
//				array[i] = array[i + jump];
//				array[i + jump] = temp;
//				temp = arr1[i];
//				arr1[i] = arr1[i + jump];
//				arr1[i + jump] = temp;
//				temp = arr2[i];
//				arr2[i] = arr2[i + jump];
//				arr2[i + jump] = temp;
//				swapped = true;
//			}
//		}
//	}
//
//}
//int main()
//{
//	ifstream in("shooting.in");
//	ofstream out("shooting.out");
//	if (!in)
//	{
//		out.close();
//		return 0;
//	}
//	if (in.eof())
//	{
//		in.close();
//		out.close();
//		return 0;
//	}
//	long long i = 0, n, k;
//	in >> n;
//	in >> k;
//	if ((k < 1) || (n > 10000) || (k > n) || (n < 1))
//	{
//		in.close();
//		out.close();
//		return 0;
//	}
//	long long* arr1 = new long long[n + 1];
//	long long* arr2 = new long long[n + 1];
//	while (in >> arr1[i])
//	{
//		if (i >= n)
//		{
//			in.close();
//			out.close();
//			delete[] arr1;
//			delete[] arr2;
//			return 0;
//		}
//		in >> arr2[i];
//		if ((arr1[i] > 1000000) || (arr2[i] > 1000000) || (arr2[i] < 1) || (arr1[i] < 1))
//		{
//			in.close();
//			out.close();
//			delete[] arr1;
//			delete[] arr2;
//			return 0;
//		}
//		i++;
//	}
//	if (i != n)
//	{
//		in.close();
//		out.close();
//		delete[] arr1;
//		delete[] arr2;
//		return 0;
//	}
//	in.close();
//	long long* arr3 = new long long[n];
//	for (long long i = 0; i < n; i++)
//		arr3[i] = arr1[i] + arr2[i];
//	rsort(arr3, arr1, arr2, n);
//	long long sum = 0;
//	for (long long i = 0; i < k; i++)
//		sum -= arr2[i];
//	for (long long i = k; i < n; i++)
//		sum += arr1[i];
//	out << sum;
//	delete[] arr1;
//	delete[] arr2;
//	delete[] arr3;
//	out.close();
//	return 0;
//}

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void main() {
    ifstream input("shooting.in");
    ofstream output("shooting.out");
     int len, v, size = 3, i;
    if (!input)
    {
        exit(0);
    }
    if (input.eof())
    {
        input.close();
        exit(0);
    }
    input >> len >> v;
    long long int** mtr = new long long int* [len];
    i = 0;
    while (i < len)
    {
        mtr[i] = new long long int[size];
        i++;
    }
    i = 0;
    for ( i = 0; i < len; i++) {
        input >> mtr[i][1] >> mtr[i][2];
        mtr[i][0] = mtr[i][1] + mtr[i][2];
    }
    i = 0;
    while ( i < len) 
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (mtr[j][0] > mtr[j + 1][0]) 
            {
                swap(mtr[j], mtr[j + 1]);
            }
        }
        i++;
    }
    long long int sum = 0;
    i = 0;
    while (i < len)
    {
        if (i < v)
        {
            sum -= mtr[i][2];
        }
        else
        {
            sum += mtr[i][1];
        }
        i++;
    }
    output << sum;
    for (int i = 0; i < len; i++)
    {
        delete[] mtr[i];
    }
    delete[] mtr;
    input.close();
    output.close();
}
