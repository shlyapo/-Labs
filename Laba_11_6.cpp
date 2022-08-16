#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	vector<int> mas;
	int n, count0 = 0, count1 = 0, count2 = 0, x;
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
				file >> n;
				for (int i = 0; i < n; i++)
				{
					file >> x;
					mas.push_back(x);
				}
			}
			for (int i = 0; i < n; i++)
			{
				if (mas[i] % 3 == 0)
					count0++;
				else if (mas[i] % 3 == 1)
					count1++;
				else
					count2++;
			}
			for (int i = 0; i < n; i++)
			{
				if (i < n - 1)
					fot << mas[i] << " ";
				else fot << mas[i] << endl;
			}
			fot << count0 << " " << count1 << " " << count2;
		}
		else
		{
			return 0;
		}
	}
}