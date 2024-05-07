#include <fstream>
#include <iostream>
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

int main(){
	ifstream in("bridge.in");
	ofstream out("bridge.out");
	if (!in){
		out.close();
		return 0;
	}
	if (in.eof()){
		in.close();
		out.close();
		return 0;
	}
	long a, i = 0, temp = 0;
	in >> a;
	if ((a > 50000) || (a < 1)){
		in.close();
		out.close();
		return 0;
	}
	 long* mtr = new  long[a + 1];
	while (in >> mtr[i]){
		if ((mtr[i] > 100) || (mtr[i] < 1) || (i >= a)){
			in.close();
			out.close();
			delete[] mtr;
			return 0;
		}
		i++;
	}
	if (i == 0){
		in.close();
		out.close();
		delete[] mtr;
		return 0;
	}
	in.close();
	int z = 0, x = a + 1;
	bubblesort(mtr, a, temp);
	if (a == 1){
		out << mtr[0];
		delete[] mtr;
		out.close();
		return 0;

	}
	if (a == 2){
		out << mtr[1];
		delete[] mtr;
		out.close();
		return 0;

	}
	if (a == 3)
	{
		out << mtr[0] + mtr[1] + mtr[2];;
		delete[] mtr;
		out.close();
		return 0;

	}
	long long* mtr1 = new long long[a];
	mtr1[0] = mtr[0];
	mtr1[1] = mtr[1];
	mtr1[2] = mtr[0] + mtr[1] + mtr[2];
	i = 3;
	while (i < a)
	{
		long long a1 = mtr1[i - 2] + mtr[0] + 2 * mtr[1] + mtr[i];
		long long a2 = mtr[0] + mtr[i] + mtr1[i - 1];
		if (a1 < a2)
		{
			mtr1[i] = a1;
		}
		else 
		{
			mtr1[i] = a2;
		}
		i++;
	}
	out << mtr1[a - 1];
	delete[] mtr1;
	delete[] mtr;
	out.close();
	return 0;
}

//#include<iostream>
//#include <fstream>
//using namespace std;
//void rsort(long long* array, long long size)
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
//				swapped = true;
//			}
//		}
//	}
//
//}
//int main()
//{
//	ifstream in("bridge.in");
//	ofstream out("bridge.out");
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
//	long long n, i = 0;
//	in >> n;
//	if ((n > 50000) || (n < 1))
//	{
//		in.close();
//		out.close();
//		return 0;
//	}
//	long long* arr1 = new long long[n + 1];
//	while (in >> arr1[i])
//	{
//		if ((arr1[i] > 100) || (arr1[i] < 1) || (i >= n))
//		{
//			in.close();
//			out.close();
//			delete[] arr1;
//			return 0;
//		}
//		i++;
//	}
//	if (i == 0)
//	{
//		in.close();
//		out.close();
//		delete[] arr1;
//		return 0;
//	}
//	in.close();
//	rsort(arr1, n);
//	if (n == 1)
//	{
//		out << arr1[0];
//		delete[] arr1;
//		out.close();
//		return 0;
//
//	}
//	if (n == 2)
//	{
//		out << arr1[1];
//		delete[] arr1;
//		out.close();
//		return 0;
//
//	}
//	if (n == 3)
//	{
//		out << arr1[0] + arr1[1] + arr1[2];;
//		delete[] arr1;
//		out.close();
//		return 0;
//
//	}
//	long long* arr2 = new long long[n];
//	arr2[0] = arr1[0];
//	arr2[1] = arr1[1];
//	arr2[2] = arr1[0] + arr1[1] + arr1[2];
//	for (long long i = 3; i < n; i++)
//	{
//		long long a1 = arr2[i - 2] + arr1[0] + 2 * arr1[1] + arr1[i];
//		long long a2 = arr1[0] + arr1[i] + arr2[i - 1];
//		if (a1 < a2)
//			arr2[i] = a1;
//		else
//			arr2[i] = a2;
//
//	}
//	out << arr2[n - 1];
//	delete[] arr2;
//	delete[] arr1;
//	out.close();
//	return 0;
//}