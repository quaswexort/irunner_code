#include <iostream>
using namespace std;
void main()
{
	long long n;
	cin >> n;
	if ((n > 1000000) || (n < 1))
	{
		exit (0);
	}
	long long summa = 1;
	long long* mtr = new long long[n];
	for (long long i = 0; i < n; i++)
	{
		cin >> mtr[i];
		summa += (mtr[i] - 1);
		if ((mtr[i] < 1) || (mtr[i] > 1000000))
		{
			delete[] mtr;
			exit(0);
		}
	}
	cout << summa;
	delete[] mtr;
}