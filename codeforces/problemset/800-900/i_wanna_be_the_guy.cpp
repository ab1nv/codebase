#include <bits/stdc++.h>
using namespace std;

#define str string
#define ll long long

int main()
{
    int n;
    cin >> n;
    set<int> t;
    int x;
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        int l1;
        cin >> l1;
        t.insert(l1);
    }

    int y;
    cin >> y;

    for (int i = 0; i < y; i++)
    {
        int l2;
        cin >> l2;
        t.insert(l2);
    }

    if (t.size() == n)
        cout << "I become the guy." << endl;
    else
        cout << "Oh, my keyboard!" << endl;
}
