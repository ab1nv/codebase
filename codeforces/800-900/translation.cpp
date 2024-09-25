#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, n;
  cin >> s >> n;

  string rev = s;
  reverse(rev.begin(), rev.end());

  if (n == rev)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
