#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int cost = 0;
    for (int i = 1; i <= c; i++)
    {
        cost += i * a;
    }
    cost = cost - b;
    if (cost < 0)
    {
        cost = 0;
    }
    cout << cost << endl;
}
