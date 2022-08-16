#include <fstream>

using namespace std;

int main()
{
	long int x;
	ifstream fout;
	ofstream fot;
	fout.open("input.txt");
	fot.open("output.txt");
	fout >> x;
	if (x > 1)
	{
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				fot << i << " ";
				x = x / i;
				i--;
			}
		}
		fot << x;
	}
	return 0;
}