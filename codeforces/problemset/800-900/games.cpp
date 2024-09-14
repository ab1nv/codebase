#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int c = 0;

    int u[n][2];

    for (int i = 0; i < n; i++)
    {
        cin >> u[i][0] >> u[i][1];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (u[i][0] == u[j][1])
                c += 1;
        }
    }

    cout << c << endl;
}
