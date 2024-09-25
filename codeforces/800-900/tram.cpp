#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int pass = 0;
  int l = 0;

  while (n--) {
    int a, b;
    cin >> a >> b;

    pass = pass - a + b;
    if (l == 0)
      l = b;

    if (l < pass)
      l = pass;
  }

  cout << l << endl;
}
