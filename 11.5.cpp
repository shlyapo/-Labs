#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	char x;
	vector<char>str;
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
				int count = 0;
				file >> x;
				str.push_back(x);
				count++;
				if (x == '/n')
				{
					char y = 0;
					for (int i = 0; i < count; i++)
					{
						if (str[i] == '/t')
							y = str[i - 1];
						break;
					}
					for (int i = count; i > 0; i--)
					{
						if (str[i - 1] != '/t')
							count++;
						else
							break;
					}
					for (int i = 0; i > count; i++)
						str[count - 1 - i] = y;
					for (int i = 0; i < count; i++)
						fot << str[i] << endl;
					str.clear();
				}
			}
		}
		else
			return 0;
	}
}