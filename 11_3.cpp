#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int>numbers;
	int x, count = 0;
	string category;
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
			while (!file.eof())
			{
				file >> x;
				numbers.push_back(x);
				count++;
			}
			sort(numbers.begin(), numbers.end());
			for (long long int i = 0; i < count- 1; i++)
			{
				for (long long int k = 1; k < count; k++)
				{
					if (i != k && numbers[i] == numbers[k])
					{
						for (long long int j = k; j < count - 1; j++)
						{
							numbers[j] = numbers[j + 1];
						}
						count--;
						i = k = 0;
					}
				}
			}
			for (int i = 0; i < count; i++)
			{
				int counter = 0, sum = 0;
				vector<int>st;
				for (int j = 1; j <= numbers[i] / 2; j++)
				{
					if (numbers[i] % j == 0)
					{
						st.push_back(j);
						counter++;
					}
				}
				for (int l = 0; l < counter; l++)
					 sum+= st[l];
				if (sum == numbers[i])
					category = "perfect";
				else if (sum < numbers[i])
					category = "deficient"; 
				else
					category = "abundant";
				fot << numbers[i] << ":" << category << endl;
				st.clear();
			}
		}
		else
			return 0;
	}
}