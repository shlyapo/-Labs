#include <iostream>
using namespace std;

int main()
{
	int N, i, count1 = 0, count2 = 0, result = 0;
	string* arr = new string[N];
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	N = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < N; i++)
	{
		if (arr[0]==")")
		{ 
			result++;
		} 
		else if (arr[N - 1] == "(")
		{
			result++;
		}
		else
		if (arr[i]=="(")
		{
			count1++;
		}
		count2 = N - count1;
		result = result + count2;
	}
	cout << result << endl;
	return 0;
}