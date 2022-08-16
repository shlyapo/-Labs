#include <fstream>
#include <string>

using namespace std;

int main()
{
    long int sum = 0, sum_sum = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a8 = 0, a9 = 0, a10 = 0, a11 = 0, a64 = 0;
    string x;
    ifstream fout;
    ofstream fot;
    fout.open("input.txt");
    fot.open("output.txt");
    fout >> x;
    if (10000 >= x.length())
    {
        if (x.length() > 6)
        {
            for (int i = 0; i < x.length(); i++)
            {
                sum += x[i] - 0x30;
                if (i % 2 == 0)
                    sum_sum += x[i] - 0x30;
                else sum_sum += -(x[i] - 0x30);
            }
            if (sum % 3 == 0)
            {
                a3++;
            }
            if (sum % 9 == 0)
            {
                a9++;
            }
            if (sum_sum % 11 == 0)
            {
                a11++;
            }
            if ((x[x.length() - 1] - 0x30) % 2 == 0)
            {
                a2++;
            }
            if (((x[x.length() - 2] - 0x30) * 10 + x[x.length() - 1] - 0x30) % 4 == 0)
            {
                a4++;
            }
            if ((x[x.length() - 1] - 0x30) == 0 || (x[x.length() - 1] - 0x30) == 5)
            {
                a5++;
            }
            if (((x[x.length() - 3] - 0x30) * 100 + (x[x.length() - 2] - 0x30) * 10 + (x[x.length() - 1] - 0x30)) % 8 == 0)
            {
                a8++;
            }
            if (a2 == 1 && a5 == 1)
            {
                a10++;
            }
            if (((x[x.length() - 6] - 0x30) * 100000 + (x[x.length() - 5] - 0x30) * 10000 + (x[x.length() - 4] - 0x30) * 1000 + (x[x.length() - 3] - 0x30) * 100 + (x[x.length() - 2] - 0x30) * 10 + (x[x.length() - 1] - 0x30)) % 64 == 0)
            {
                a64++;
            }
            if (a2 == 1 && a3 == 1)
            {
                a6++;
            }
        }
        else
        {
            for (int i = 0; i < x.length(); i++)
            {
                sum = sum * 10 + x[i] - 0x30;
            }
            if (sum % 2 == 0)
            {
                a2 += 1;
            }
            if (sum % 3 == 0)
            {
                a3 += 1;
            }
            if (sum % 4 == 0)
            {
                a4 += 1;
            }
            if (sum % 5 == 0)
            {
                a5 += 1;
            }
            if (sum % 6 == 0)
            {
                a6 += 1;
            }
            if (sum % 8 == 0)
            {
                a8 += 1;
            }
            if (sum % 9 == 0)
            {
                a9 += 1;
            }
            if (sum % 10 == 0)
            {
                a10 += 1;
            }
            if (sum % 11 == 0)
            {
                a11 += 1;
            }
            if (sum % 64 == 0)
            {
                a64 += 1;
            }
        }
        fot << a2 << " " << a3 << " " << a4 << " " << a5 << " " << a6 << " " << a8 << " " << a9 << " " << a10 << " " << a11 << " " << a64 << endl;

        return 0;
    }
    return 0;
}
