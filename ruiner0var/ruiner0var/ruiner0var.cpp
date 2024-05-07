#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream input("in.txt");
	ofstream output("out.txt");
	if (!input)
	{
		output.close();
		return 0;
	}
	if (input.eof())
	{
		input.close();
		output.close();
		return 0;
	}
	const int n = 100;
	int b = 0, j = 0;
	long long mtr[n];
	while (input >> mtr[b])
	{
		if ((mtr[b] > 1000000000) || (b >= n))
		{
			input.close();
			output.close();
			return 0;
		}
		b++;
	}
	if (b == 0)
	{
		input.close();
		output.close();
		return 0;
	}
	input.close();
	int* mtr_0 = new int[b];
	for (int i = 0; i < b; i++)
	{
		mtr_0[i] = 0;
		long long b;
		int c, m = 0;
		for (j = 0; j < 10; ++j)
		{
			c = 0;
			b = mtr[i];
			while (b > 0)
			{
				if (b % 10 == j) c++;
				b /= 10;
			}
			if ((c != 0) && (c >= m))
			{
				m = c;
				mtr_0[i] = j;
			}
		}
	}
	for (int i = 0; i < b; i++) {
		j = 0;
		while (j < b - 1)
		{
			if (mtr[j] > mtr[j + 1])
			{
				long long temp = mtr[j];
				mtr[j] = mtr[j + 1];
				mtr[j + 1] = temp;
				int temp1 = mtr_0[j];
				mtr_0[j] = mtr_0[j + 1];
				mtr_0[j + 1] = temp1;
			}
			j++;
		}
	}
	output << mtr[0] << ":" << mtr_0[0] << endl;
	for (int i = 1; i < b; i++)
	{
		if (mtr[i - 1] != mtr[i])
		{
			output << mtr[i] << ":" << mtr_0[i] << endl;
		}
	}

	output.close();
	delete[] mtr_0;
	return 0;
}