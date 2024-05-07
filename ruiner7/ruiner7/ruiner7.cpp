#include<iostream>
#include<string>
using namespace std;
bool digitTry(string str);
bool digitTry(string str)
{
	int tmp = 0;
	if (str[tmp] == '0')
	{
		return false;
	}
	return str.find_first_not_of("0123456789", tmp) == std::string::npos;
}
void main()
{
	string years, str = "";
	long years_0 = 0, years_1 = 0, position = 0;
	getline(cin, years);
	if ((position = years.find_first_of(' '), position) != std::string::npos)
	{
		str = years.substr(0, position);
		int n = str.size();
		if (n == 1)
		{
			if (digitTry(str))
			{
				years_0 = stoi(str);
			}
			else
			{
				exit(0);
			}
		}
		else
			if (n == 2)
			{
				if (digitTry(str))
				{
					years_0 = stoi(str);
				}
				else
				{
					exit(0);
				}
			}
			else
				if ((n < 7) && (n > 2))
				{
					if ((str[n - 2] == 'A') && (str[n - 1] == 'D'))
					{
						str.erase(n - 2);
						if (digitTry(str))
						{
							years_0 = stoi(str);
						}
						else
						{
							exit(0);
						}
					}
					else
						if ((str[n - 2] == 'B') && (str[n - 1] == 'C'))
						{
							str.erase(n - 2);
							if (digitTry(str))
							{
								years_0 = stoi(str) * (-1);
							}
							else
							{
								exit(0);
							}
						}
						else
							if ((n < 5) && (digitTry(str)))
							{
								years_0 = stoi(str);
							}
							else
							{
								exit(0);
							}
				}
		str = years.substr(position + 1, years.size() - 1 - position);
		n = str.size();
		if (n == 1)
		{
			if (digitTry(str))
			{
				years_1 = stoi(str);
			}
			else
			{
				exit(0);
			}
		}
		else
			if (n == 2)
			{
				if (digitTry(str))
				{
					years_1 = stoi(str);
				}
				else 
				{
					exit(0);
				}
			}
			else
				if ((n < 7) && (n > 2))
				{
					if ((str[n - 1] == 'D') && (str[n - 2] == 'A'))
					{
						str.erase(n - 2);
						if (digitTry(str))
						{
							years_1 = stoi(str);
						}
						else
						{
							exit(0);
						}
					}
					else
						if ((str[n - 2] == 'B') && (str[n - 1] == 'C'))
						{
							str.erase(n - 2);
							if (digitTry(str))
							{
								years_1 = stoi(str) * (-1);
							}
							else
							{
								exit(0);
							}
						}
						else
							if ((digitTry(str)) && (n < 5))
							{
								years_1 = stoi(str);
							}
							else
							{
								exit(0);
							}
				}
	}
	else
	{
		exit(0);
	}
	if ((fabs(years_0) > 3000) || (fabs(years_1) > 3000))
	{
		exit(0);
	}
	if (years_0 == years_1)
	{
		cout << 0;
	}
	else
	{
		if (years_0 * years_1 < 0)
		{
			if (years_1 > years_0)
			{
				cout << years_1 - years_0 - 1;
			}
			else
			{
				cout << years_1 - years_0 + 1;
			}
		}
		else
		{
			cout << years_1 - years_0;
		}
	}
}