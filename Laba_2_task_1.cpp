#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    long int x, z = 0;
    double y = 0;
    ifstream fout;
    ofstream fot;
    fout.open("input.txt");
    fot.open("output.txt");
    fout >> x;
    if (x > 0)
    {
        y = log10(x);
        double c = ceil(y);
        int b = x % 10;
        if (b != 0)
        {
            y = c;
        }
        else
        {
            y += 1;
        }
        for (int i = x; i > 0; i /= 10)
        {
            z += i % 10;
        }
        fot << y << " " << z << endl;
    }
    if (x == 0)
    {
        y += 1;
        fot << y << " " << z << endl;
    }
}