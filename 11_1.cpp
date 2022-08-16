#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector<int>numbers;
    vector<int>numbers2;
    int x, count = 0, k = 0, n;
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
            while (!file.eof)
            {
                file >> n;
                for (int i = 0; i < n; i++)
                {
                    file >> x;
                    numbers.push_back(x);
                }
            }
            for (int i = 0; i < n; i++)
                cout << numbers[i] << endl;
            sort(numbers.begin(), numbers.end());
            for (int i = 0; i < n; i++)
                numbers2.push_back(numbers[n - 1 - i]);
            for (int i = 0; i < n; i++)
                cout << numbers[i] << endl;
            for (long long int i = 0; i < n - 1; i++)
            {
                for (long long int k = 1; k < n; k++)
                {
                    if (i != k && numbers2[i] == numbers2[k])
                    {
                        for (long long int j = k; j < n - 1; j++)
                        {
                            numbers2[j] = numbers2[j + 1];
                        }
                        n--;
                        i = k = 0;
                    }
                }
            }
            for (int i = 0; i < n; i++)
                cout << numbers2[i] << endl;
            for (int i = 0; i < n; i++)
            {
                if (numbers2[i] == 1)
                    fot << numbers2[i] << ":" << "composite" << endl;
                else
                {
                    int count1 = 0;
                    for (long int j = 2; j <= sqrt(numbers2[i]); j++)
                    {
                        if (numbers2[i] % j == 0)
                            count1++;
                    }
                    if (count1 != 0)
                        fot << numbers2[i] << ":" << "composite" << endl;
                    else
                        fot << numbers2[i] << ":" << "prime" << endl;
                }
            }
        }
        else
        {
            n = 0;
            return 0;
        }
    }
}