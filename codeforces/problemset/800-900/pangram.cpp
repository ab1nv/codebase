#include <bits/stdc++.h>
using namespace std;

#define str string
#define ll long long

int main()
{
    int n;
    cin >> n;
    str s;
    cin >> s;
    if (n < 26)
    {
        cout << "NO" << endl;
        return 0;
    }

    set<char> l;
    for (int i = 0; i < n; i++)
    {
        char c = tolower(s[i]);
        l.insert(c);
    }

    if (l.size() == 26)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
