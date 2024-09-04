#include <bits/stdc++.h>
using namespace std;

int main()
{
    string num;
    cin >> num;

    int d;

    for (char c : num)
    {
        if (c != '4' && c != '7')
            return false;
        else
            return true;
    }
}
