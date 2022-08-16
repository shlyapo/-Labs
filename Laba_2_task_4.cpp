#include <fstream>

using namespace std;

int main() 
{
    long int x, y, nod, a, b;
    ifstream fout;
    ofstream fot;
    fout.open("input.txt");
    fot.open("output.txt");
    fout >> x >> y;
    long long c = (long long)x * (long long)y;
    if (x > y)
    {
        a = x;
        b = y;
    }
    else
    {
        a = y;
        b = x;
    }
    while (a % b != 0)
    {
        long int z = a % b;
        a = b;
        b = z;
    }
    nod = b;
    long long nok = c / (long long)nod;
    fot << nod << " " << nok << endl;
    return 0;
}