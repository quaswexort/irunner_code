//#include<iostream>
//#include <fstream>
//using namespace std;
//void bubblesort(long long* mtr, long long n, long long temp)
//{
//	for (int i = 0; i < n - 1; i++)
//		{
//		if (mtr[i] > mtr[i + 1]) 
//		{
//			temp = mtr[i];
//			mtr[i] = mtr[i + 1];
//			mtr[i + 1] = temp;
//		}
//	}
//}
//int main()
//{
//	ifstream input("gratis.in");
//	ofstream output("gratis.out");
//	if (!input)
//	{
//		output.close();
//		return 0;
//	}
//	if (input.eof())
//	{
//		input.close();
//		output.close();
//		return 0;
//	}
//	long long n = 0, z = 0;
//	input >> n;
//	input >> z;
//	if ((z > 10000) || (z < 1) || (n > 100000) || (n < 1))
//	{
//		input.close();
//		output.close();
//		return 0;
//	}
//	long long i = 0;
//	long long* mtr = new long long[n + 1];
//	while (input >> mtr[i])
//	{
//		if ((mtr[i] > z) || (mtr[i] < 1) || (i >= n))
//		{
//			input.close();
//			output.close();
//			delete[] mtr;
//			return 0;
//		}
//		i++;
//	}
//	if (i == 0)
//	{
//		input.close();
//		output.close();
//		delete[] mtr;
//		return 0;
//	}
//	input.close();
//	long long temp = 0;
//	bubblesort(mtr, n, temp);
//	mtr[n] = 0;
//	long long k = 0;
//	i = 0;
//	while (i < n)
//	{
//		long long temp = 0, j = 0;
//		while (j > i)
//		{
//			if (mtr[i] == 0)
//			{
//				k--;
//				break;
//			}
//			else
//			{
//				if ((mtr[i] + mtr[j] > z) || (mtr[j] == 0))
//				{
//					continue;
//				}
//				else
//				{
//					temp++;
//					break;
//				}
//			}
//			j--;
//		}
//		mtr[i] = 0;
//		if (!temp)
//			k++;
//		else
//		{
//			mtr[j] = 0;
//			k++;
//		}
//		i++;
//	}
//	output << k;
//	delete[] mtr;
//	output.close();
//	return 0;
//}

#include<iostream>
#include <fstream>
using namespace std;
void bubblesort(long* mtr, long n, long temp)
{
	for (int i = 0; i < n - 1; i++)
		{
		if (mtr[i] > mtr[i + 1]) 
		{
			temp = mtr[i];
			mtr[i] = mtr[i + 1];
			mtr[i + 1] = temp;
		}
	}
}
void main()
{
	ifstream input("gratis.in");
	ofstream output("gratis.out");
	if (!input)
	{
		output.close();
		exit(0);
	}
	if (input.eof())
	{
		input.close();
		output.close();
		exit(0);
	}
	long n = 0, v = 0, temp = 0;
	input >> n;
	input >> v;
	if ((n < 1) || (n > 100000) || (v < 1) || (v > 10000))
	{
		input.close();
		output.close();
		exit(0);
	}
	long i = 0;
	long* mtr = new long[n + 1];
	while (input >> mtr[i])
	{
		if ((mtr[i] > v) || (mtr[i] < 1) || (i >= n))
		{
			input.close();
			output.close();
			delete[] mtr;
			exit(0);
		}
		i++;
	}
	if (i == 0)
	{
		input.close();
		output.close();
		delete[] mtr;
		exit(0);
	}
	input.close();
	bubblesort(mtr, n, temp);
	mtr[n] = 0;
	long k = 0;
	i = 0;
	while (i < n)
	{
		long temp = 0, j;
		for (j = n; j > i; j--)
		{
			if (mtr[i] == 0)
			{
				k--;
				break;
			}
			else
			{
				if ((mtr[i] + mtr[j] > v) || (mtr[j] == 0))
				{
					continue;
				}
				else
				{
					temp++;
					break;
				}
			}
		}
		mtr[i] = 0;
		if (!temp)
		{
			k++;
		}
		else
		{
			mtr[j] = 0;
			k++;
		}
		i++;
	}
	output << k;
	delete[] mtr;
	output.close();
	
}