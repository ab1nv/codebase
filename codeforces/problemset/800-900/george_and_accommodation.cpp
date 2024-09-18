#include <bits/stdc++.h>
using namespace std;

#define str string

int main() {
  int n;
  cin >> n;
  int c = 0;

  while (n--) {
    int a, b;
    cin >> a >> b;
    if (a + 2 <= b)
      c += 1;
  }

  cout << c << endl;
}
