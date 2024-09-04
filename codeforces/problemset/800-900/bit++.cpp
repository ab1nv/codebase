#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    int x = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string statement;
        cin >> statement;

        if (statement.find("++") != string::npos)
        {
            x++;
        }
        else if (statement.find("--") != string::npos)
        {
            x--;
        }
    }
    cout << x;
}
