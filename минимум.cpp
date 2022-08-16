#include <iostream>
#include <list>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
    int q, x;
    string n;
    list<int>list1;
    list<int>list2;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> n;
        if (n == "+R")
        {
            cin >> x;
            list1.push_back(x);
            auto start = +list1.begin();
            auto end = list1.end();
            list2.assign(start, end);
            list2.sort();
            int min = list2.front();
            cout << min << endl;
            list2.clear();
        }
        else if (n == "+L")
        {
            cin >> x;
            list1.push_front(x);
            auto start = +list1.begin();
            auto end = list1.end();
            list2.assign(start, end);
            list2.sort();
            int min = list2.front();
            cout << min << endl;
            list2.clear();
        }
        else if (n == "-L")
        {
            list1.pop_front();
            auto start = +list1.begin();  
            auto end = list1.end();
            list2.assign(start, end); 
            if (!list1.empty())
            {
                list2.sort();
                int min = list2.front();
                cout << min << endl;
            }
            else
                cout << "-1" << endl;
            list2.clear();
        }
        else if (n == "-R")
        {
            list<int>list2;
            list1.pop_back();
            auto start = +list1.begin();  
            auto end = list1.end();
            list2.assign(start, end); 
            if (!list1.empty())
            {
                list2.sort();
                int min = list2.front();
                cout << min << endl;
            }
            else
                cout << "-1" << endl;
            list2.clear();
        }
    }
}