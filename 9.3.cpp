#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t, y, n;
	cin >> t;
	int* arr = new int[t];
	for (int i = 0; i < t; i++)
		cin >> n;
	vector<vector<int>> ab;
	int* arryb= new int[n];
	int* arrya = new int[n];
	vector<vector<int>>ab2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
			cin >> ab[i][j];
		for (int l = 0; l < ab[i][0]; l++)
			cin >> ab2[i][l];
	}

}
