#include <iostream>
using namespace std;

int main()
{
	long long k, a=1; /*?- ?????? ?????*/
	cin >> k; /*??????? ?????? ? ?????????? */
	long long arr[34] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35 };
	long long arry[10]; /*??????, ? ??????? ????? ?????? ?????*/
	for (int i = 0; i < 10; i++) /*????, ? ??????? ???????? ????? ??????????? ??????*/
	{
		int counter = 0;
		for (int l = 0; l < 10; l++) /*????, ? ??????? ???????? ????????(????????) ????? ????????????? ?? ?????????? ????????*/
		{
				while (counter != k - 2) /*??????? ? ??????? ????? ?????, ??????? ???????? ?? ???????, ???? ??????? ?? ????? ????? ??????? ?????????? ???? ?????*/
				{
					for (int j = 0; j < 34; j++)
					{
					a *= arr[j + l];
					arry[i] = a;
					counter++;
					}
				}
		}
	}
	for (int i = 0; i < 10; i++)/* ??????? ?????*/
	{
		cout << arry[i] << endl;
	}
	return 0;
}
//?????: 304888345?29, 384424435E29, 384424435E30, 297928937E31, 19067452E32, 104870986E33.

