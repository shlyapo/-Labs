#include <iostream>

using namespace std;

int main()
{
	int a, b, n, i = 0, j;
	cin >> a;
	cin >> n;
	int* arr = new int[n];
	for (j = 0; j < n; j++)
		arr[j] = 0;

	if (n * 9 - a >= 0)
	{
		while (a > 0)
		{
			if (a > 9)
			{
				arr[i] = 9;
				i++;
				a -= 9;
			}
			else
			{
				arr[i] = a;
				i++;
				a = 0;
			}
		}
		for (j = 0; j < n; j++)
			cout << arr[j];
	}
	else {
		cout << -1;
	}
	return 0;
}