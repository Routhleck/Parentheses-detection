#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
stack<char> a;

int main()
{
    int i, n, p = 0, q = 0;
    char s[1024], b;
    gets_s(s);
    n = strlen(s);
    for (i = 0; i < n; i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            a.push(s[i]);
        else if (s[i] == '}')
        {
            if (a.empty())
            {
                p = 1;
                break;
            }
            b = a.top();
            if (b == '{')
                a.pop();
            else
            {
                p = 1;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (a.empty())
            {
                p = 1;
                break;
            }
            b = a.top();
            if (b == '[')
                a.pop();
            else
            {
                p = 1;
                break;
            }
        }
        else if (s[i] == ')')
        {
            if (a.empty())
            {
                p = 1;
                break;
            }
            b = a.top();
            if (b == '(')
                a.pop();
            else
            {
                p = 1;
                break;
            }
        }
    }
    if (!a.empty())
        q = 1;
    if (p == 1 || q == 1)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}