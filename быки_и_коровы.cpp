#include <iostream>
#include <cstring>

using namespace std;

void num(int x, int& x1, int& x10 , int& x100, int& x1000)
{
    x1 = x % 10; 
    x=(x-x%10)/10;
    x10 = x % 10;
    x = (x - x % 10) / 10;
    x100 = x % 10; 
    x = (x - x % 10) / 10;
    x1000= x % 10;
}

bool true_number(int x)
{
    int x1000, x100, x10, x1;
    num(x, x1000, x100, x10, x1);
    return (x1 >= 1) && (x1 <= 9) && (x1!= x10) && (x1!= x100) && (x1 != x1000) && (x100!= x10) && (x100!= x1000) && (x10!= x1000);
}

bool bulls_cows(int number_1, int number_2, int bulls, int cows)
{
    int x1000_1, x1000_2, x100_1, x100_2, x10_1, x10_2, x1_1, x1_2;
    num(number_1, x1000_1, x100_1, x10_1, x1_1);
    num(number_2, x1000_2, x100_2, x10_2, x1_2);
    return bulls == ((x1000_1 == x1000_2) + (x100_1 == x100_2) + (x10_1 == x10_2) + (x1_1 == x1_2))
        && cows == ((x1000_1 == x100_2) + (x1000_1 == x1_2) + (x1000_1 == x10_2) + (x100_1 == x1000_2) + (x100_1 == x10_2) + (x100_2 == x1_2) + (x10_1 == x1000_2) + (x10_1 == x100_2) + (x10_1 == x1_2) + (x1_1 == x1000_2) + (x1_1 == x100_2) + (x1_1 == x10_2));
}

int main()
{
    const int Size = 10000;
    bool bad[Size];
    for (int i = 0; i < Size; i++)
    {
        bad[i] = !true_number(i);
    }
    while (true)
    {
        int bulls, cows, j;
        for ( j = 0; j < Size&& bad[j]; j++);
            cout << j << " " << endl;
            cout << "bulls" << endl;
            cin >> bulls;
            cout << "cows" << endl;
            cin >> cows;
            if (bulls == 4 && cows == 0)
            {
                cout << "true number " << endl;
                break;
            }
            for (int i = 0; i < Size; i++)
            {
                bad[i] = bad[i] || !bulls_cows(i, j, bulls, cows);
            }
    }
}