#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<int>numbers;
	int x, n = 0;
	string a;
	ifstream file;
	ofstream fot;
	while (!(file.is_open() && fot.is_open()))
	{
		if (!file.is_open())
		{
			file.open("in.txt");
		}
		if (!fot.is_open())
		{
			fot.open("out.txt");
		}
	}
	if (file.is_open() && fot.is_open())
	{
		if (file.peek() != EOF)
		{
			file >> n;
			if (n != 0)
			{
				for (int i = 0; i < n; i++)
				{
					file >> x;
					numbers.push_back(x);
				}
				sort(numbers.begin(), numbers.end());
				for (long long int i = 0; i < n - 1; i++)
				{
					for (long long int k = 1; k < n; k++)
					{
						if (i != k && numbers[i] == numbers[k])
						{
							for (long long int j = k; j < n - 1; j++)
							{
								numbers[j] = numbers[j + 1];
							}
							n--;
							i = k = 0;
						}
					}
				}
				for (int i = 0; i < n; i++)
				{
					vector<int>st;
					int b = numbers[i];
					double y = ceil(log10(b));
					if (b > 0)
					{
						for (long long int j = 0; j < y; j++)
						{
							st.push_back(b % 10);
							b = (b - b % 10) / 10;
						}
					}
					else
						st.push_back(b);
					for (int j = 0; j < y; j++)
					{
						if (st[j] == st[y - 1 - j])
							a = "palindrome";
						else
						{
							a = "non-palindrome";
							break;
						}
					}
					fot << numbers[i] << ":" << a << endl;
					st.clear();
				}
			}
		}
		else
			return 0;
	}
}
