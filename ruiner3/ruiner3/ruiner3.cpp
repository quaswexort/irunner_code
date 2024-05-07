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
	int* mtr = new int[n + 1];
	int  platoMax = 0, platoMin = n, kolvo = 0, c = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> mtr[i];
		if (abs(mtr[i]) > 10e+6)
		{
			delete[] mtr;
			return 0;
		}
	}
	mtr[n] = 10e+6 + 1;
	while (i < n)
	{
		if (mtr[i] == mtr[i + 1])
			c++;
		if ((mtr[i] != mtr[i + 1]) && (c != 1))
		{
			kolvo++;
			if (c < platoMin)
				platoMin = c;
			if (c > platoMax)
				platoMax = c;
			c = 1;
		}
		i++;
	}
	if (kolvo == 0)
	{
		platoMin = 0;
		platoMax = 0;
	}
	cout << kolvo << " " << platoMax << " " << platoMin << endl;
	delete[] mtr;
	return 0;
}