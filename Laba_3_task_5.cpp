#include <iostream>

using namespace std;

int main()
{
    int N, x, kount = 0, j;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        j = 1;
        kount++;
        while (x > 0)
        {
            if (((x % 2 != 0) && (j % 2 == 0)) || ((x % 2 == 0) && (j % 2 != 0)))
            {
                kount--;
                break;
            }
            x /= 10;
            j++;
        }
    }
    cout << kount << endl;
    return 0;
}