#include <iostream>
using namespace std;
int main()
{
	int n, i = 0;
	cin >> n;
	if ((n < 1) || (n > 10e+6))
	{
		return 0;
	}
	int* mtr = new int[n];
	int k = 0;
	while (i < n)
	{
		cin >> mtr[i];
		if (abs(mtr[i]) > 10e+9)
		{
			delete[] mtr;
			return 0;
		}
		i++;
	}

	for (i = 1; i < n; i++)
	{
		if (mtr[i] == mtr[0])
			k++;
	}
	cout << k << endl;
	delete[] mtr;
	return 0;
}