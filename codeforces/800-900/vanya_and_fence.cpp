#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, h;
  cin >> n >> h;
  int wd = n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > h)
      wd += 1;
  }

  cout << wd << endl;
}
