#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	short a, b, c, d;
	cin >> a >> b >> c;
	d = b + c - a; // y-������� � ������ ����� 1 �����, x-������� ����� 1 �����;
	// z-������� � ������ ����� ������ �����, t-������� ����� ������ �����;
	//����� 2x+2y=a(), 2z-2y+2x=b(), 2y+2t-2x=c(),2t-2x+2z-2y=d, 4t+4z=a+b+c+d
	// a+d=2t+2z; 2a+2d=a+b+c+d;
	//d=b+c-a;
	cout << setprecision(6) << d;
	return 0;
}