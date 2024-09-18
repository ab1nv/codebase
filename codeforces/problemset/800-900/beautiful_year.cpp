#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin >> n;
  bool r = false;
  int y = stoi(n);

  while (r != true) {
    y += 1;
    n = to_string(y);
    r = true;

    set<char> c;
    for (int i = 0; i < n.length(); i++) {
      if (c.count(n[i]) > 0) {
        r = false;
        break;
      }
      c.insert(n[i]);
    }
  }

  cout << y << endl;
}
