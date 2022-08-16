#include <iostream>

using namespace std;

int main()
{
	double numerator1, denominator1, numerator2, denominator2, result = 2;
	cin >> numerator1 >> denominator1;
	cin >> numerator2 >> denominator2;
	if ((numerator1 / denominator1) == (numerator2 / denominator2))
	{
		result -= 2;
	}
	if ((numerator1 / denominator1) > (numerator2 / denominator2))
	{
		result--;
	}
	if ((numerator1 / denominator1) < (numerator2 / denominator2))
	{
		result -= 3;
	}
	cout << result << endl;
	return 0;
}