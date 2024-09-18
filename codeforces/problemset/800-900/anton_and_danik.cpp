#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n;

  string s;
  cin >> s;

  int an = 0;
  int dn = 0;

  for (char c : s) {
    if (c == 'A')
      an += 1;
    else
      dn += 1;
  }

  if (an > dn)
    cout << "Anton" << endl;
  if (an < dn)
    cout << "Danik" << endl;
  if (an == dn)
    cout << "Friendship" << endl;
}
