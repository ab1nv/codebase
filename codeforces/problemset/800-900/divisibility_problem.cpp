#include <bits/stdc++.h>
using namespace std;

#define str string
#define ll long long

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        ll a, b;
        cin >> a >> b;

        if (a % b == 0)
            cout << 0 << endl;
        else
            cout << b - (a % b) << endl;
    }
}
