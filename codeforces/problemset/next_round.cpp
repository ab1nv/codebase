#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> scores(n);

    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }

    int advanced = 0;
    int threshold = scores[k - 1];

    for (int i = 0; i < n; i++)
    {
        if (scores[i] >= threshold && scores[i] > 0)
        {
            advanced++;
        }
    }

    cout << advanced;
}