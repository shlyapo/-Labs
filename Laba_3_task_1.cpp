#include <iostream>

using namespace std;

int main()
{
	int N, i, kount = 0, max = 0, min = 0, flag = 0, kount2 = 0;
	cin >> N;
	int* array = new int[N];
	for (i = 0; i < N; i++)
	{
		cin >> array[i];
	}
	for (i = 0; i < N - 1; i++)
	{
		if (array[i] == array[i + 1])
		{
			kount2++;
			kount = 1;
			int j = i + 1;
			while (array[i] == array[j])
			{
				i = j;
				j++;
				kount++;
			}
			if (flag == 0)
			{
				min = kount;
				max = kount;
				flag++;
			}
			else
			{
				if (max < kount)
					max = kount;
				if (min > kount)
					min = kount;
			}
		}
	}
	cout << kount2 << " " << max << " " << min;
	return 0;
}