#include <iostream>

using namespace std;

int main()
{
	int n, m, i, j, ** ary, kount = 0;
	cin >> n;
	cin >> m;
	ary = new int* [n];
	for (i = 0; i < n; i++)
	{
		ary[i] = new int[m];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> ary[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (ary[i][j] == 1)
			{
					int l = i;
					int k = j;
					while (ary[l][k] == 1)
					{
						if (l% k == 0)
						{
							kount++;
							break;
						}
					}
			}
		}
	}
	cout << kount << endl;
	for (i = 0; i < n; i++)
	{
		delete[] ary[i];
	}
	delete[] ary;
	return 0;
}
