#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;

        // (c−a)+(b−c)
        int lowest = a;
        for (int j = a; j <= b; j++)
        {
            if ((j - a) + (b - j) < lowest)
                lowest = j;
        }
        cout << ((lowest - a) + (b - lowest)) << endl;
    }
}
