#include <fstream>
#include <string>

using namespace std;

int main()
{
    string result;
    long int x;
    ifstream fout;
    ofstream fot;
    fout.open("input.txt");
    fot.open("output.txt");
    fout >> x;
    if (x == 1)
    {
        result = "NO";
        fot << result;
        return 0;
    }
    result = "YES";
    for (long int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            result = "NO";
        }
    }
    fot << result;
    return 0;
}