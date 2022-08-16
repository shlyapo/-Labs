#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector<int>numbers;
    vector<int>numbers2;
    int x, count = 0, k = 0, n=0;
    ifstream file;
    ofstream fot;
    while (!(file.is_open() && fot.is_open()))
    {
        if (!file.is_open())
        {
            file.open("in.txt");
        }
        if (!fot.is_open())
        {
            fot.open("out.txt");
        }
    }
    if (file.is_open() && fot.is_open())
    {
        if (file.peek() != EOF)
        {
                file >> n;
                for (int i = 0; i < n; i++)
                {
                    file >> x;
                    numbers.push_back(x);
                }
            sort(numbers.begin(), numbers.end());
            int a = 0, b = 0;
            for (int i = 0; i <(n / 2); i++)
            {
                a = numbers[i];
                b = numbers[n - i - 1];
                numbers[i] = b;
                numbers[n - 1 - i] = a;
            }
            for (long long int i = 0; i < n - 1; i++)
            {
                for (long long int k = 1; k < n; k++)
                {
                    if (i != k && numbers[i] == numbers[k])
                    {
                        for (long long int j = k; j < n - 1; j++)
                        {
                            numbers[j] = numbers[j + 1];
                        }
                        n--;
                        i = k = 0;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                    int count1 = 0;
                    for (long int j = 2; j <= sqrt(numbers[i]); j++)
                    {
                        if (numbers[i] % j == 0)
                            count1++;
                    }
                    if (count1 != 0)
                        fot << numbers[i] << ":" << "composite" << endl;
                    else
                        fot << numbers[i] << ":" << "prime" << endl;
            }
        }
        else
        {
            return 0;
        }
    }
}