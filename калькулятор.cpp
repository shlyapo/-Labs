//работает с +, -, *, (), / и отрицательными числами
#include <iostream>
#include <conio.h>
#include <string>
#include <stack>
#include <queue>

using namespace std;

queue<char> change(const string& example)
{
    stack<char> st;
    queue<char> opn;
    for (auto i : example)
    {
        if (i >= '0' && i <= '9')
            opn.push(i);
        else if (i == '+' || i == '-' || i == '*' || i == '/')
        {
            if (st.empty() != true && (st.top() == '*' || st.top() == '/'))
            {
                if (i == '*' || i == '/')
                {
                    opn.push(st.top());
                    st.top() = i;
                }
                else if (i == '+' || i == '-')
                {
                    while (st.empty() != true && st.top() != '(')
                    {
                        opn.push(st.top());
                        st.pop();
                    }
                    st.push(i);
                }
            }
            else
            {
                if (opn.empty() != true && opn.back() >= '0' && opn.back() <= '9')
                    opn.push(';');
                else if (((st.empty() != true && st.top() == '(') || opn.empty() == true) && i == '-')
                    opn.push('_');
                if (opn.back() != '_')
                    st.push(i);
            }
        }
        else if (i == '(')
        {
            if (opn.empty() != true && opn.back() >= '0' && opn.back() <= '9')
            {
                opn.push(';');
                st.push('*');
            }
            st.push(i);
        }
        else if (i == ')')
        {
            while (st.empty() != true && st.top() != '(')
            {
                opn.push(st.top());
                st.pop();
            }
            if (st.empty() != true)
                st.pop();
        }
    }
    while (st.empty() != true)
    {
        opn.push(st.top());
        st.pop();
    }
    return opn;
}

int calc(queue<char> example)
{
    stack<int> res;
    bool minus = false, op = false;
    int temp;
    res.push(0);
    while (example.empty() != true)
    {
        if (example.front() == '_')
        {
            minus = true;
            example.pop();
        }
        else if (example.front() >= '0' && example.front() <= '9')
        {
            if (op == true) { res.push(0.0); op = false; }
            while (example.empty() != true && example.front() >= '0' && example.front() <= '9')
            {
                if ((example.front() == '0' && res.top() == 0.0) == false)
                {
                        res.top() = res.top() * 10 + example.front() - 48;
                }
                example.pop();
            }
        }
        else if (example.front() == ';' ||example.front() == '+' || example.front() == '-' ||example.front() == '*' || example.front() == '/')
        {
            if (minus == true)
            {
                minus = false;
                res.top() = -res.top();
            }
            if (example.front() == ';')
            {
                res.push(0);
                example.pop();
            }
            else if (res.size() > 1)
            {
                temp = res.top();
                res.pop();
                switch (example.front())
                {
                case '+':
                    res.top() += temp;
                    break;
                case '-':
                    res.top() -= temp;
                    break;
                case '*':
                    res.top() *= temp;
                    break;
                case '/':
                    res.top() /= temp;
                    break;
                }
                op = true;
                example.pop();
            }
        }
    }
    return res.top();
}

int main()
{
    string example;
    queue<char> gen;
    cout << "Enter:";
    getline(cin, example);
    gen = change(example);
    cout << calc(gen);
}